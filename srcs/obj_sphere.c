/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:23:25 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 15:34:22 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_get_dt(double vars[6], t_obj *obj, t_ray *ray)
{
	t_v3	n_pos;
	t_v3	n_dir;

	n_pos = v3_sub(ray->pos, obj->pos);
	n_dir = v3_inv_rot(ray->dir, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	n_pos = v3_inv_rot(n_pos, -obj->rot.x, -obj->rot.y, -obj->rot.z);
	vars[0] = (n_dir.x * n_dir.x) + (n_dir.y * n_dir.y) + (n_dir.z * n_dir.z);
	vars[1] = (2 * (n_dir.x * (n_pos.x)))
		+ (2 * (n_dir.y * (n_pos.y)))
		+ (2 * (n_dir.z * (n_pos.z)));
	vars[2] = ((n_pos.x * n_pos.x))
		+ ((n_pos.y * n_pos.y))
		+ ((n_pos.z * n_pos.z))
		- (obj->var * obj->var);
	if (vars[0] == 0.25)
		vars[3] = (vars[1] * vars[1]) - vars[2];
	else
		vars[3] = (vars[1] * vars[1]) - (4 * vars[0] * vars[2]);
}

static void			s_solve_hit(double vars[6], t_ray *ray)
{
	if (vars[3] > 0)
	{
		vars[4] = ((-vars[1]) + sqrt(vars[3])) / (2 * vars[0]);
		vars[5] = ((-vars[1]) - sqrt(vars[3])) / (2 * vars[0]);
		ray->hit.t = (vars[4] < vars[5]) ? vars[4] : vars[5];
		ray->hit.t = (ray->hit.t == vars[4] && vars[4]
			< (double)0) ? vars[5] : ray->hit.t;
		ray->hit.t = (ray->hit.t == vars[5] && vars[5]
			< (double)0) ? vars[4] : ray->hit.t;
	}
	else if (vars[3] == 0)
	{
		ray->hit.t = (-vars[1]) / (2 * vars[0]);
	}
}

void				rt_sphere(t_obj *obj, t_ray *ray)
{
	double		vars[6];

	s_get_dt(vars, obj, ray);
	if (vars[3] >= (double)0)
	{
		s_solve_hit(vars, ray);
		if (ray->hit.t >= (double)0)
		{
			ray->hit.done = 1;
			ray->hit.pos = v3_sum(ray->pos, v3_mul(ray->dir, ray->hit.t));
			ray->hit.obj = obj;
		}
	}
}

t_v3				norm_sphere(t_obj *obj, t_v3 p)
{
	return (v3_normalized(v3_sub(p, obj->pos)));
}
