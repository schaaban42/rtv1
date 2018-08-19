/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:13:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/27 02:55:27 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

char	*ft_join(char *format, ...)
{
	va_list		args;
	char		*last;
	char		*s;
	int			i;

	va_start(args, format);
	last = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '0')
			last = ft_strjoin_free(last, va_arg(args, char*));
		else if (format[i] == '1')
		{
			s = va_arg(args, char*);
			last = ft_strjoin_free(last, s);
			s ? ft_strdel(&s) : 0;
		}
		i++;
	}
	va_end(args);
	return (last);
}
