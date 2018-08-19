/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:00:51 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/09 15:16:22 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit_base(int c, int base)
{
	if (base <= 10)
	{
		if (c >= '0' && c <= '0' + base - 1)
			return (1);
	}
	else
	{
		if (base > 16)
			return (0);
		if (c >= '0' && c <= '9')
			return (1);
		else
		{
			if (c >= 'A' && c <= 'A' + base - 11)
				return (1);
			else if (c >= 'a' && c <= 'a' + base - 11)
				return (1);
		}
	}
	return (0);
}
