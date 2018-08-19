/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:25:01 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/16 19:36:35 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				v3_set(t_v3 *v, double newX, double newY, double newZ)
{
	v->x = newX;
	v->y = newY;
	v->z = newZ;
}

void				v3_reset(t_v3 *v)
{
	v->x = 0.0;
	v->y = 0.0;
	v->z = 0.0;
}

t_v3				v3_cpy(t_v3 v)
{
	return ((t_v3)
	{
		v.x,
		v.y,
		v.z
	});
}

int					v3_cmp(t_v3 v1, t_v3 v2)
{
	if (v1.x == v2.x
		&& v1.y == v2.y
		&& v1.z == v2.z)
		return (1);
	return (0);
}

void				v3_print(t_v3 v, int block)
{
	if (block)
	{
		printf("X : %f\nY : %f\nZ : %f\n", v.x, v.y, v.z);
	}
	else
	{
		printf("X : %f Y : %f Z : %f\n", v.x, v.y, v.z);
	}
}
