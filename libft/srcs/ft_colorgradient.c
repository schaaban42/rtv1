/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorgradient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:43:04 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/20 14:06:15 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

static int	color_gradient(int cs, int ce, double value)
{
	int		c1[3];
	int		c2[3];
	int		cf[3];

	if (value >= 1)
		return (ce);
	if (value < 0)
		return (cs);
	c1[0] = cs & 0xFF0000;
	c1[1] = cs & 0x00FF00;
	c1[2] = cs & 0x0000FF;
	c2[0] = ce & 0xFF0000;
	c2[1] = ce & 0x00FF00;
	c2[2] = ce & 0x0000FF;
	cf[0] = (c1[0] + (int)((double)(c2[0] - c1[0]) * value)) & 0xFF0000;
	cf[1] = (c1[1] + (int)((double)(c2[1] - c1[1]) * value)) & 0x00FF00;
	cf[2] = (c1[2] + (int)((double)(c2[2] - c1[2]) * value)) & 0x0000FF;
	return (cf[0] | cf[1] | cf[2]);
}

int			ft_colorgradient(double value, int n, ...)
{
	va_list		args;
	int			i;
	int			last;
	int			new;

	i = 0;
	va_start(args, n);
	if (value >= 1)
		value = 0.999999;
	if (value < 0)
		value = 0;
	while (i < n)
	{
		last = va_arg(args, int);
		if ((int)(value * (n - 1)) == i)
		{
			new = va_arg(args, int);
			return (color_gradient(last, new, 
				(value - ((1.0 / (double)(n - 1)) * i)) * (n - 1)));
		}
		i++;
	}
	va_end(args);
	return (0);
}
