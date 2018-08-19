/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 02:33:17 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/17 11:19:42 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				to_rad(double degrees)
{
	return (degrees * RT_PI / 180.0);
}

double				to_deg(double radians)
{
	return (radians * 180.0 / RT_PI);
}

Uint32				color_value(Uint32 color, double value)
{
	return (ft_colorgradient(value, 2, 0, color) | 0xff000000);
}
