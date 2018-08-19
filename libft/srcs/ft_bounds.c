/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:35:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/07 20:38:17 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_dbounds(double n, double min, double max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	else
		return (n);
}
