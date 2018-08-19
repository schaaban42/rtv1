/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:10:55 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/19 04:40:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				rt_plane(t_obj *obj, t_ray *ray)
{
	t_v3	n_pos;
	t_v3	n_dir;
	double	n;

	n_pos = v3_sub(ray->pos, obj->pos);
	n_dir = v3_rot(ray->dir, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	n_pos = v3_rot(n_pos, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	n = ((n_dir.x * obj->obj_norm.x)
		+ (n_dir.y * obj->obj_norm.y)
		+ (n_dir.z * obj->obj_norm.z));
	if (n == 0)
		return ;
	ray->t = (-(
		(n_pos.x * obj->obj_norm.x)
		+ (n_pos.y * obj->obj_norm.y)
		+ (n_pos.z * obj->obj_norm.z))) / n;
	if (ray->t > 0.0)
	{
		ray->hit.done = 1;
		ray->hit.pos = v3_sum(ray->pos, v3_mul(ray->dir, ray->t));
		ray->hit.obj = obj;
	}
}

t_v3				norm_plane(t_obj *obj, t_v3 ray_dir)
{
	t_v3		cnorm;
	double		a;
	double		dir;

	cnorm = v3_cpy(obj->obj_norm);
	cnorm = v3_rot(cnorm, obj->rot.x, obj->rot.y, obj->rot.z);
	a = to_deg(acos(v3_ang(cnorm, v3_normalized(ray_dir))));
	dir = (a > 90.0 && a < 270.0) ? 1.0 : -1.0;
	if (dir < 0)
	{
		cnorm = v3_mul(cnorm, -1.0);
	}
	return (v3_normalized(cnorm));
}
