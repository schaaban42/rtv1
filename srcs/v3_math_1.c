/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_math_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 12:56:30 by schaaban          #+#    #+#             */
/*   Updated: 2018/09/26 16:28:33 by schaaban         ###   ########.fr       */
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

double				v3_norm(t_v3 v)
{
	return (sqrt(
		(v.x * v.x)
		+ (v.y * v.y)
		+ (v.z * v.z)));
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

t_v3				v3_normalized(t_v3 v)
{
	return (v3_div(v, v3_norm(v)));
}

double				v3_dist(t_v3 v1, t_v3 v2)
{
	return (v3_norm(v3_sub(v2, v1)));
}

t_v3				v3_rot_x(t_v3 v, double a)
{
	a = to_rad(a);
	return ((t_v3)
	{
		v.x,
		(v.y * cos(a)) + (v.z * -sin(a)),
		(v.y * sin(a)) + (v.z * cos(a))
	});
}

t_v3				v3_rot_y(t_v3 v, double a)
{
	a = to_rad(a);
	return ((t_v3)
	{
		(v.x * cos(a)) + (v.z * sin(a)),
		v.y,
		(v.z * cos(a)) + (v.x * -sin(a))
	});
}

t_v3				v3_rot_z(t_v3 v, double a)
{
	a = to_rad(a);
	return ((t_v3)
	{
		(v.x * cos(a)) - (v.y * sin(a)),
		(v.x * sin(a)) + (v.y * cos(a)),
		v.z
	});
}

t_v3				v3_rot(t_v3 v, double ax, double ay, double az)
{
	return (
		v3_rot_z(v3_rot_y(v3_rot_x(v, ax), ay), az)
	);
}

t_v3				v3_inv_rot(t_v3 v, double ax, double ay, double az)
{
	return (
		v3_rot_x(v3_rot_y(v3_rot_z(v, az), ay), ax)
	);
}

double				v3_ang(t_v3 v1, t_v3 v2)
{
	double		cosa;

	v1 = v3_normalized(v1);
	v2 = v3_normalized(v2);
	cosa = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	return (cosa);
}
