/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:16:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/09/25 23:45:12 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*static void			s_get_dt(double vars[4], t_obj *obj, t_ray *ray)
{
	t_v3	n_pos, n_dir;

	n_pos = v3_sub(ray->pos, obj->pos);
	n_dir = ray->dir;
	vars[0] = (n_dir.x * n_dir.x) + (n_dir.z * n_dir.z);
	vars[1] = (2 * (n_dir.x * (n_pos.x - obj->pos.x)))
		+ (2 * (n_dir.z * (n_pos.z - obj->pos.z)));
	vars[2] = ((n_pos.x * n_pos.x) + (obj->pos.x * obj->pos.x))
		+ ((n_pos.z * n_pos.z) + (obj->pos.z * obj->pos.z))
		- (obj->obj_r * obj->obj_r);
	if (vars[0] == 0.25)
		vars[3] = (vars[1] * vars[1]) - vars[2];
	else
		vars[3] = (vars[1] * vars[1]) - (4 * vars[0] * vars[2]);
}*/

static void			s_get_dt(double vars[4], t_obj *obj, t_ray *ray)
{
	t_v3	n_pos;
	t_v3	n_dir;

	n_pos = v3_sub(ray->pos, obj->pos);
	n_dir = v3_inv_rot(ray->dir, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	n_pos = v3_inv_rot(n_pos, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	vars[0] = (n_dir.x * n_dir.x) + (n_dir.z * n_dir.z);
	vars[1] = (2 * (n_dir.x * (n_pos.x)))
		+ (2 * (n_dir.z * (n_pos.z)));
	vars[2] = ((n_pos.x * n_pos.x))
		+ ((n_pos.z * n_pos.z))
		- (obj->obj_r * obj->obj_r);
	if (vars[0] == 0.25)
		vars[3] = (vars[1] * vars[1]) - vars[2];
	else
		vars[3] = (vars[1] * vars[1]) - (4 * vars[0] * vars[2]);
}

void				rt_cylinder(t_obj *obj, t_ray *ray)
{
	double		vars[4];

	s_get_dt(vars, obj, ray);
	if (vars[3] > 0)
	{
		double t1, t2;

		t1 = ((-vars[1]) + sqrt(vars[3])) / (2 * vars[0]);
		t2 = ((-vars[1]) - sqrt(vars[3])) / (2 * vars[0]);
		ray->t = (t1 < t2) ? t1 : t2;
		if (ray->t > 0.0)
		{
			ray->hit.done = 1;
			ray->hit.pos = v3_sum(ray->pos, v3_mul(ray->dir, ray->t));
			ray->hit.obj = obj;
		}
	}
	else if (vars[3] == 0)
	{
		ray->t = (-vars[1]) / (2 * vars[0]);
		if (ray->t > 0.0)
		{
			ray->hit.done = 1;
			ray->hit.pos = v3_sum(ray->pos, v3_mul(ray->dir, ray->t));
			ray->hit.obj = obj;
		}
	}
}

t_v3				norm_cylinder(t_obj *obj, t_v3 p)
{
	t_v3	n;

	n = v3_sub(p, obj->pos);
	n = v3_inv_rot(n, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	n.y = 0;
	n = v3_rot(n, obj->rot.x, obj->rot.y, obj->rot.z);
	n = v3_normalized(n);
	return (n);
}
