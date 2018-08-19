/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:57:26 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 20:36:10 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pf_args(const char *format, int *i, va_list *arg_list)
{
	if (format[++(*i)] == 's')
		ft_putstr(va_arg(*arg_list, char*));
	if (format[(*i)] == 'd')
		ft_putnbr(va_arg(*arg_list, int));
	if (format[(*i)++] == 'c')
		ft_putchar(va_arg(*arg_list, int));
}

int				ft_printf(const char *restrict format, ...)
{
	int		c_count;
	int		i;
	va_list	arg_list;

	i = 0;
	c_count = 0;
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			pf_args(format, &i, &arg_list);
		else
			ft_putchar(format[i++]);
		c_count++;
	}
	va_end(arg_list);
	return (c_count);
}
