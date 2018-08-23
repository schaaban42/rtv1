/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:10:55 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/20 22:46:20 by schaaban         ###   ########.fr       */
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

t_v3				norm_plane(t_obj *obj, t_v3 ray_pos, t_v3 ray_hit, int debug)
{
	t_v3		n1;
	t_v3		n2;

	n1 = v3_rot(v3_cpy(obj->obj_norm), obj->rot.x, obj->rot.y, obj->rot.z);
	n2 = v3_rot(v3_mul(v3_cpy(obj->obj_norm), -1.0),
		obj->rot.x, obj->rot.y, obj->rot.z);
	if (debug == 1)
	{
		printf("debug:\n");
		v3_print(obj->obj_norm, 0);
		v3_print(obj->rot, 0);
		v3_print(n1, 0);
		v3_print(n2, 0);
		v3_print(v3_sum(ray_hit, n1), 0);
		v3_print(v3_sum(ray_hit, n2), 0);
		v3_print(ray_pos, 0);
		v3_print(ray_hit, 0);
	}
	return ((v3_norm(v3_sub(v3_sum(ray_hit, n1), ray_pos)) < v3_norm(v3_sub(v3_sum(ray_hit, n2), ray_pos))) ? n1 : n2);
}
