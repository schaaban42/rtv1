/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:10:55 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/20 22:19:26 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				rt_plane(t_obj *obj, t_ray *ray)
{
	t_v3	n_pos;
	t_v3	n_dir;
	double	n;

	n_pos = v3_sub(ray->pos, obj->pos);
	n_dir = v3_inv_rot(ray->dir, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	n_pos = v3_inv_rot(n_pos, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	n = ((n_dir.x * PLANE_NORM.x)
		+ (n_dir.y * PLANE_NORM.y)
		+ (n_dir.z * PLANE_NORM.z));
	if (n == 0)
		return ;
	ray->hit.t = (-(
		(n_pos.x * PLANE_NORM.x)
		+ (n_pos.y * PLANE_NORM.y)
		+ (n_pos.z * PLANE_NORM.z))) / n;
	if (ray->hit.t >= (double)0)
	{
		ray->hit.done = 1;
		ray->hit.pos = v3_sum(ray->pos, v3_mul(ray->dir, ray->hit.t));
		ray->hit.obj = obj;
	}
}

t_v3				norm_plane(t_obj *obj, t_v3 ray_pos, t_v3 ray_hit)
{
	t_v3		n1;
	t_v3		n2;

	n1 = v3_rot(v3_cpy(PLANE_NORM), obj->rot.x, obj->rot.y, obj->rot.z);
	n2 = v3_mul(n1, -1.0);
	return ((v3_norm(v3_sub(v3_sum(ray_hit, n1), ray_pos))
		<= v3_norm(v3_sub(v3_sum(ray_hit, n2), ray_pos))) ? n1 : n2);
}
