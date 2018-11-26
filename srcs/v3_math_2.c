/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_math_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:47:03 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 14:47:32 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
