/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:36:47 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:21 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_process_shine(t_rt *rt, Uint32 *color, t_v3 norm)
{
	t_v3	vref;
	double	angle;

	vref = v3_sub(v3_normalized(v3_sub(rt->ray.hit.pos, rt->ray.pos)),
		v3_mul(norm, 2 * v3_ang(v3_sub(rt->ray.hit.pos, rt->ray.pos), norm)));
	angle = v3_ang(vref, v3_sub(rt->light.pos, rt->light.hit.pos));
	if (angle >= (double)0)
		*color = color_add(*color, color_value(rt->light_color,
			pow(angle, rt->ray.hit.obj->shine) * rt->light_diff));
}

void				light_diffuse(t_rt *rt, Uint32 *color)
{
	t_v3	norm;

	if (rt->ray.hit.obj->type == 's')
		norm = norm_sphere(rt->ray.hit.obj, rt->ray.hit.pos);
	else if (rt->ray.hit.obj->type == 'c')
		norm = norm_cylinder(rt->ray.hit.obj, rt->ray.hit.pos);
	else if (rt->ray.hit.obj->type == 'p')
	{
		if (!v3_cmp((norm = norm_plane(rt->ray.hit.obj, rt->light.pos,
			rt->ray.hit.pos)), norm_plane(rt->ray.hit.obj,
			rt->ray.pos, rt->ray.hit.pos)))
			return;
	}
	else
		norm = norm_cone(rt->ray.hit.obj, rt->ray.hit.pos);
	*color = color_add(*color, color_value(color_sub(rt->light_color,
		color_sub(0xffffff, rt->ray.hit.obj->color)), v3_ang(norm,
		v3_sub(rt->light.pos, rt->ray.hit.pos)) * rt->light_diff));
	if (rt->ray.hit.obj->shine)
		s_process_shine(rt, color, norm);
}
