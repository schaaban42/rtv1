/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:41:47 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/21 04:52:06 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			s_init_camera(t_rt *rt)
{
	rt->camera.pos = (t_v3){0, -25, 0};
	rt->camera.rot = (t_v3){0, 0, 0};
	rt->camera.dir = v3_normalized((t_v3){0, 0, 1});
	rt->camera.v_up = v3_rot_x(rt->camera.dir, 90);
	rt->camera.v_right = v3_rot_y(rt->camera.dir, 90);
	rt->camera.dir = v3_rot(rt->camera.dir,
		rt->camera.rot.x, rt->camera.rot.y, rt->camera.rot.z);
	rt->camera.v_up = v3_rot(rt->camera.v_up, 
		rt->camera.rot.x, rt->camera.rot.y, rt->camera.rot.z);
	rt->camera.v_right = v3_rot(rt->camera.v_right, 
		rt->camera.rot.x, rt->camera.rot.y, rt->camera.rot.z);
	rt->camera.fov = 100;
	rt->camera.vp_dist = (rt->w / 2.0) / tan(to_rad(rt->camera.fov / 2.0));
}

void				rtv1_init(t_rt *rt)
{
	rt->w = 600;
	rt->h = 600;
	rt->exit = 0;
	rt->objs_cnt = 7;
	rt->light.pos = (t_v3){0, -100, 50};
	s_init_camera(rt);
	if (!(rt->objs = (t_obj*)ft_memalloc(sizeof(t_obj) * (rt->objs_cnt))))
		error_handler(RT_ERR_MALLOC, rt);
	rt->objs[0].type = 's';
	rt->objs[0].pos = (t_v3){-75, 0, 200};
	rt->objs[0].rot = (t_v3){0, 0, 0};
	rt->objs[0].obj_r = 35;
	rt->objs[0].color = 0xffff0000;
	rt->objs[1].type = 's';
	rt->objs[1].pos = (t_v3){0, -50, 200};
	rt->objs[1].rot = (t_v3){0, 0, 0};
	rt->objs[1].obj_r = 35;
	rt->objs[1].color = 0xff00ff00;
	rt->objs[2].type = 's';
	rt->objs[2].pos = (t_v3){75, 0, 200};
	rt->objs[2].rot = (t_v3){0, 0, 0};
	rt->objs[2].obj_r = 35;
	rt->objs[2].color = 0xff0000ff;
	rt->objs[3].type = 'p';
	rt->objs[3].pos = (t_v3){0, 0, 400};
	rt->objs[3].rot = (t_v3){-90, 0, 0};
	rt->objs[3].obj_norm = (t_v3){0, -1, 0};
	rt->objs[3].color = 0xffffff00;
	rt->objs[4].type = 'p';
	rt->objs[4].pos = (t_v3){0, 50, 0};
	rt->objs[4].rot = (t_v3){180, 0, 0};
	rt->objs[4].obj_norm = (t_v3){0, -1, 0};
	rt->objs[4].color = 0xff00ffff;
	rt->objs[5].type = 'p';
	rt->objs[5].pos = (t_v3){-250, 0, 0};
	rt->objs[5].rot = (t_v3){0, 0, 90};
	rt->objs[5].obj_norm = (t_v3){0, -1, 0};
	rt->objs[5].color = 0xffffffff;
	rt->objs[6].type = 'p';
	rt->objs[6].pos = (t_v3){250, 0, 0};
	rt->objs[6].rot = (t_v3){0, 0, 90};
	rt->objs[6].obj_norm = (t_v3){0, -1, 0};
	rt->objs[6].color = 0xffffffff;
	/*rt->objs[3].type = 'p';
	rt->objs[3].pos = (t_v3){0, 300, 0};
	rt->objs[3].rot = (t_v3){0, 0, 0};
	rt->objs[3].obj_norm = (t_v3){0, -1, 0};
	rt->objs[3].color = 0xff00ffff;*/
}
