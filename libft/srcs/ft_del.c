/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:01:48 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/19 08:39:53 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		del_arrays(char c, va_list *args)
{
	if (c == 'v')
		ft_a2ddel((void***)va_arg(*args, void***));
	else if (c == 's')
		ft_a2ddel((void***)va_arg(*args, char***));
}

static void		del_ptr(char c, va_list *args)
{
	if (c == 'v')
		ft_memdel((void**)va_arg(*args, void**));
	else if (c == 's')
		ft_strdel((char**)va_arg(*args, char**));
	else if (c == 'i')
		ft_memdel((void**)va_arg(*args, int**));
}

void			ft_del(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '1')
			del_ptr(format[i++ + 1], &args);
		else if (format[i] == '2')
			del_arrays(format[i++ + 1], &args);
		i++;
	}
	va_end(args);
}
