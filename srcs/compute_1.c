/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 02:42:56 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:50 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_update_ray(t_obj *obj, t_ray *ray)
{
	if (obj->type == 's')
		rt_sphere(obj, ray);
	else if (obj->type == 'c')
		rt_cylinder(obj, ray);
	else if (obj->type == 'p')
		rt_plane(obj, ray);
	else if (obj->type == 'o')
		rt_cone(obj, ray);
}

static void		s_ray_trace(t_rt *rt)
{
	t_obj		*it;

	it = rt->objs;
	rt->ray.b_hit = hit_empty();
	while (it)
	{
		rt->ray.hit = hit_empty();
		s_update_ray(it, &(rt->ray));
		if (rt->ray.hit.done)
		{
			if (!rt->ray.b_hit.done)
				rt->ray.b_hit = hit_copy(rt->ray.hit);
			if (rt->ray.hit.t < rt->ray.b_hit.t - 0.0000000001)
				rt->ray.b_hit = hit_copy(rt->ray.hit);
		}
		it = it->next;
	}
}

static void		s_light_trace(t_rt *rt)
{
	t_obj		*it;

	it = rt->objs;
	rt->light.screen_pos = v3_cpy(rt->ray.screen_pos);
	rt->light.dir = v3_sub(rt->ray.hit.pos, rt->light.pos);
	s_update_ray(rt->ray.hit.obj, &(rt->light));
	rt->light.b_hit = hit_copy(rt->light.hit);
	while (it)
	{
		rt->light.hit = hit_empty();
		s_update_ray(it, &(rt->light));
		if (rt->light.hit.done)
		{
			if (rt->light.hit.t < rt->light.b_hit.t - 0.0000000001)
				rt->light.b_hit = hit_copy(rt->light.hit);
		}
		it = it->next;
	}
}

static Uint32		s_trace_get_color(t_rt *rt)
{
	Uint32		color;

	color = 0;
	s_ray_trace(rt);
	rt->ray.hit = hit_copy(rt->ray.b_hit);
	if (rt->ray.hit.done)
	{
		s_light_trace(rt);
		rt->light.hit = hit_copy(rt->light.b_hit);
		if (rt->light.hit.done)
		{
			color = color_value(rt->ray.hit.obj->color, RT_LIGHT_SHADOW);
			if (!(rt->ray.hit.obj != rt->light.hit.obj
				|| rt->light.hit.t < (double)0.9999
				|| rt->light.hit.t > (double)1.0001))
				light_diffuse(rt, &color);
		}
	}
	return (color | 0xff000000);
}

static void			s_put_rays(t_rt *rt)
{
	int		i;
	int		j;

	i = -1;
	while (++i < rt->h)
	{
		j = -1;
		while (++j < rt->w)
		{
			ray_reset_hit(&rt->ray);
			ray_reset_hit(&rt->light);
			rt->ray.pos = rt->camera.pos;
			rt->ray.dir = v3_sub(v3_sum(rt->camera.vp_up_left,
				v3_sum(
					v3_mul(rt->camera.v_right, j), v3_mul(rt->camera.v_up, -i)
				)), rt->ray.pos);
			rt->ray.screen_pos = (t_v3){j, i, 0};
			ft_put_pixel(j, i, s_trace_get_color(rt), rt);
		}
		if (i % (rt->h / 30) == 0)
			SDL_UpdateWindowSurface(rt->win);
	}
}

void				rtv1_compute(t_rt *rt)
{
	double		scale_h;

	scale_h = ((double)rt->h / (double)rt->w) * (double)RT_BASE_WIDTH;
	rt->camera.dir = v3_rot(rt->camera.dir,
		rt->camera.rot.x, rt->camera.rot.y, rt->camera.rot.z);
	rt->camera.v_up = v3_mul(v3_rot(rt->camera.v_up, 
		rt->camera.rot.x, rt->camera.rot.y, rt->camera.rot.z),
		(scale_h / (double)rt->h));
	rt->camera.v_right = v3_mul(v3_rot(rt->camera.v_right, 
		rt->camera.rot.x, rt->camera.rot.y, rt->camera.rot.z),
		(double)RT_BASE_WIDTH / rt->w);
	rt->camera.vp_up_left = v3_sub(
		v3_sum(rt->camera.pos,
			v3_sum(
				v3_mul(rt->camera.dir, rt->camera.vp_dist),
				v3_mul(rt->camera.v_up, (rt->h / 2.0))
			)),
		v3_mul(rt->camera.v_right, (rt->w / 2.0)));
	s_put_rays(rt);
}
