/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:30:51 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/15 21:54:55 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			s_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int					ft_atoi_base(const char *str, int base)
{
	int		result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str >= 0 && (*str < 27 || (*str > 27 && *str <= 32)))
		str++;
	if ((*str == '-' || *str == '+') && base == 10)
		if (*str++ == '-')
			sign = -1;
	while (*str != '\0')
	{
		if (s_value(*str) >= 0 && s_value(*str) < base)
			result = (result * base) + (s_value(*str++));
		else
			return (result * sign);
		if (*str == '\0')
			return (result * sign);
	}
	return (0);
}
