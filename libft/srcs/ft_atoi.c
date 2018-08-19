/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:33:13 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 15:10:41 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str >= 0 && (*str < 27 || (*str > 27 && *str <= 32)))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			result = (result * 10) + (*str++ - '0');
		else
			return (result * sign);
		if (*str == '\0')
			return (result * sign);
	}
	return (0);
}
