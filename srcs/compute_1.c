/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 02:42:56 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/19 01:13:16 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*static void			s_place_ray(t_rt *rt, int i, int j)
{
	

	int		n;

	n = -1;
	while (++n < rt->objs_cnt)
	{

	}
	
	t_obj		sphere;

	sphere.pos = (t_v3){-100, 0, 100};
	double		a, b, c, r = 50;

	a = (rt->ray.dir.x * rt->ray.dir.x) + (rt->ray.dir.y * rt->ray.dir.y) + (rt->ray.dir.z * rt->ray.dir.z);
	b = 2 * (rt->ray.dir.x * (rt->ray.pos.x - sphere.pos.x)
		+ rt->ray.dir.y * (rt->ray.pos.y - sphere.pos.y)
		+ rt->ray.dir.z * (rt->ray.pos.z - sphere.pos.z));
	c = ((rt->ray.pos.x - sphere.pos.x) * (rt->ray.pos.x - sphere.pos.x)
		+ (rt->ray.pos.y - sphere.pos.y) * (rt->ray.pos.y - sphere.pos.y)
		+ (rt->ray.pos.z - sphere.pos.z) * (rt->ray.pos.z - sphere.pos.z)) - (r * r);
	double dt;

	if (a == 0.25)
		dt = (b * b) - c;
	else
		dt = (b * b) - (4 * a * c);
	
	if (dt > 0)
	{
		double t1, t2;

		t1 = ((-b) + sqrt(dt)) / (2 * a);
		t2 = ((-b) - sqrt(dt)) / (2 * a);
		rt->ray.t = (t1 < t2) ? t1 : t2;

		rt->ray.hit_pos = v3_sum(rt->ray.pos, v3_mul(rt->ray.dir, rt->ray.t));
		ft_put_pixel(rt->ray.screen_pos.x, rt->ray.screen_pos.y, 0xffff0000, rt);
	}
	else if (dt == 0)
	{
		rt->ray.t = (-b) / (2 * a);
		rt->ray.hit_pos = v3_sum(rt->ray.pos, v3_mul(rt->ray.dir, rt->ray.t));
		ft_put_pixel(rt->ray.screen_pos.x, rt->ray.screen_pos.y, 0xff0000, rt);
	}

	t_obj		sphere2;

	sphere2.pos = (t_v3){-75, 0, 1000};

	a = (rt->ray.dir.x * rt->ray.dir.x) + (rt->ray.dir.y * rt->ray.dir.y) + (rt->ray.dir.z * rt->ray.dir.z);
	b = 2 * (rt->ray.dir.x * (rt->ray.pos.x - sphere2.pos.x)
		+ rt->ray.dir.y * (rt->ray.pos.y - sphere2.pos.y)
		+ rt->ray.dir.z * (rt->ray.pos.z - sphere2.pos.z));
	c = ((rt->ray.pos.x - sphere2.pos.x) * (rt->ray.pos.x - sphere2.pos.x)
		+ (rt->ray.pos.y - sphere2.pos.y) * (rt->ray.pos.y - sphere2.pos.y)
		+ (rt->ray.pos.z - sphere2.pos.z) * (rt->ray.pos.z - sphere2.pos.z)) - (r * r);

	if (a == 0.25)
		dt = (b * b) - c;
	else
		dt = (b * b) - (4 * a * c);
	
	if (dt > 0)
	{
		double t1, t2;

		t1 = ((-b) + sqrt(dt)) / (2 * a);
		t2 = ((-b) - sqrt(dt)) / (2 * a);
		rt->ray.t = (t1 < t2) ? t1 : t2;

		rt->ray.hit_pos = v3_sum(rt->ray.pos, v3_mul(rt->ray.dir, rt->ray.t));
		ft_put_pixel(rt->ray.screen_pos.x, rt->ray.screen_pos.y, 0xff0000ff, rt);
	}
	else if (dt == 0)
	{
		rt->ray.t = (-b) / (2 * a);
		rt->ray.hit_pos = v3_sum(rt->ray.pos, v3_mul(rt->ray.dir, rt->ray.t));
		ft_put_pixel(rt->ray.screen_pos.x, rt->ray.screen_pos.y, 0xff0000ff, rt);
	}
}*/

static void			s_cam_rt(t_obj *obj, t_ray *ray)
{
	if (obj->type == 's')
	{
		rt_sphere(obj, ray);
	}
	else if (obj->type == 'c')
	{
		rt_cylinder(obj, ray);
	}
	else if (obj->type == 'p')
	{
		rt_plane(obj, ray);
	}
	else if (obj->type == 'o')
	{
		rt_cone(obj, ray);
	}
}

static Uint32		s_ray_trace(t_rt *rt)
{
	Uint32		color;
	int			i;

	i = -1;
	rt->ray.b_hit = hit_empty();
	while (++i < rt->objs_cnt)
	{
		s_cam_rt(&(rt->objs[i]), &(rt->ray));
		if (rt->ray.hit.done)
		{
			if (!rt->ray.b_hit.done)
				rt->ray.b_hit = hit_copy(rt->ray.hit);
			if (hit_closer(rt->ray, rt->ray.hit, rt->ray.b_hit))
				rt->ray.b_hit = hit_copy(rt->ray.hit);
		}
	}
	color = 0;
	if (rt->ray.hit.done)
	{
		rt->ray.hit = hit_copy(rt->ray.b_hit);

		rt->light.dir = v3_sub(rt->ray.hit.pos, rt->light.pos);
		i = -1;
		rt->light.b_hit = hit_empty();
		while (++i < rt->objs_cnt)
		{
			s_cam_rt(&(rt->objs[i]), &(rt->light));
			if (rt->light.hit.done)
			{
				if (!rt->light.b_hit.done)
					rt->light.b_hit = hit_copy(rt->light.hit);
				if (hit_closer(rt->light, rt->light.hit, rt->light.b_hit))
					rt->light.b_hit = hit_copy(rt->light.hit);
			}
		}
		color = rt->ray.hit.obj->color;
		if (rt->light.hit.done)
		{
			rt->light.hit = hit_copy(rt->light.b_hit);
			if (rt->light.hit.obj->type != rt->ray.hit.obj->type)
				color = color_value(color, 0.1);
			else
			{
				if (rt->light.hit.obj->type == 's')
				{
					t_v3	n;
					double	cosa;

					n = norm_sphere(rt->light.hit.obj, rt->ray.hit.pos);
					cosa = v3_ang(n, v3_sub(rt->light.pos, rt->light.hit.pos));
					color = (Uint32)ft_colorgradient(cosa, 2, 0, rt->ray.hit.obj->color) | 0xff000000;
					double brill = 0.90;
					if (cosa > brill)
						color = (Uint32)ft_colorgradient(((cosa - brill) * (1.0 / (1.0 - brill))), 2, color, 0xffffff) | 0xff000000;
				}
				else if (rt->light.hit.obj->type == 'p')
				{
					t_v3	n;
					double	cosa;

					n = norm_plane(rt->light.hit.obj, rt->light.dir);
					if (!v3_cmp(n, norm_plane(rt->light.hit.obj, rt->ray.dir)))
						color = color_value(color, 0.1);
					else
					{
						cosa = v3_ang(n, v3_sub(rt->light.pos, rt->light.hit.pos));
						color = (Uint32)ft_colorgradient(cosa, 2, 0, rt->ray.hit.obj->color) | 0xff000000;
						double brill = 0.98;
						if (cosa > brill)
							color = (Uint32)ft_colorgradient(((cosa - brill) * (1.0 / (1.0 - brill))), 2, color, 0xffffff) | 0xff000000;
					}
				}
			}
		}
	}
	return (color);
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
			ft_put_pixel(j, i, s_ray_trace(rt), rt);
		}
	}
}

void				rtv1_compute(t_rt *rt)
{
	rt->camera.vp_up_left = v3_sub(
		v3_sum(rt->camera.pos,
			v3_sum(
				v3_mul(rt->camera.dir, rt->camera.vp_dist),
				v3_mul(rt->camera.v_up, (rt->h / 2.0))
			)),
		v3_mul(rt->camera.v_right, (rt->w / 2.0)));
	s_put_rays(rt);
}
