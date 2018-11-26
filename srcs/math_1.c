/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 02:33:17 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/21 15:29:19 by schaaban         ###   ########.fr       */
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

Uint32				color_add(Uint32 color1, Uint32 color2)
{
	Uint32	rgb[3];

	rgb[0] = ((color1 & 0xff0000) >> 16) + ((color2 & 0xff0000) >> 16);
	rgb[1] = ((color1 & 0x00ff00) >> 8) + ((color2 & 0x00ff00) >> 8);
	rgb[2] = ((color1 & 0x0000ff)) + ((color2 & 0x0000ff));
	rgb[0] = (rgb[0] > 255) ? 255 : rgb[0];
	rgb[1] = (rgb[1] > 255) ? 255 : rgb[1];
	rgb[2] = (rgb[2] > 255) ? 255 : rgb[2];
	return (((rgb[0] << 16) | (rgb[1] << 8) | (rgb[2])) | 0xff000000);
}

Uint32				color_sub(Uint32 color1, Uint32 color2)
{
	int	rgb[3];

	rgb[0] = ((color1 & 0xff0000) >> 16) - ((color2 & 0xff0000) >> 16);
	rgb[1] = ((color1 & 0x00ff00) >> 8) - ((color2 & 0x00ff00) >> 8);
	rgb[2] = ((color1 & 0x0000ff)) - ((color2 & 0x0000ff));
	rgb[0] = (rgb[0] > 255) ? 255 : rgb[0];
	rgb[1] = (rgb[1] > 255) ? 255 : rgb[1];
	rgb[2] = (rgb[2] > 255) ? 255 : rgb[2];
	rgb[0] = (rgb[0] < 0) ? 0 : rgb[0];
	rgb[1] = (rgb[1] < 0) ? 0 : rgb[1];
	rgb[2] = (rgb[2] < 0) ? 0 : rgb[2];
	return (((rgb[0] << 16) | (rgb[1] << 8) | (rgb[2])) | 0xff000000);
}
