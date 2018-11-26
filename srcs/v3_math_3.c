/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_math_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:48:11 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 14:48:17 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v3				v3_sum(t_v3 v1, t_v3 v2)
{
	return ((t_v3)
	{
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	});
}

t_v3				v3_sub(t_v3 v1, t_v3 v2)
{
	return ((t_v3)
	{
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	});
}

t_v3				v3_mul(t_v3 v, double value)
{
	return ((t_v3)
	{
		v.x * value,
		v.y * value,
		v.z * value
	});
}

t_v3				v3_div(t_v3 v, double value)
{
	return ((t_v3)
	{
		v.x / value,
		v.y / value,
		v.z / value
	});
}
