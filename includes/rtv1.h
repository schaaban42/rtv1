/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:37:43 by schaaban          #+#    #+#             */
/*   Updated: 2018/09/26 21:46:45 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include <SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define RT_PI				(double)3.1415926535897932

# define RT_LIGHT_SHADOW	(double)0.05

# define RT_ERR_MALLOC		1
# define RT_ERR_SDL_INIT	2
# define RT_ERR_ARG			3

# if SDL_BYTEORDER == SDL_BIG_ENDIAN
#  define RT_SDL_RMASK		0xff000000
#  define RT_SDL_GMASK		0x00ff0000
#  define RT_SDL_BMASK		0x0000ff00
#  define RT_SDL_AMASK		0x000000ff
# else
#  define RT_SDL_RMASK		0x000000ff
#  define RT_SDL_GMASK		0x0000ff00
#  define RT_SDL_BMASK		0x00ff0000
#  define RT_SDL_AMASK		0xff000000
# endif

typedef struct		s_v3
{
	double			x;
	double			y;
	double			z;
}					t_v3;

typedef struct		s_cam
{
	t_v3			pos;
	t_v3			rot;
	t_v3			dir;
	t_v3			v_up;
	t_v3			v_right;
	double			fov;
	double			vp_dist;
	t_v3			vp_up_left;
}					t_cam;

typedef struct		s_obj
{
	t_v3			pos;
	t_v3			rot;

	double			obj_r;
	double			obj_ang;
	t_v3			obj_norm;

	char			type;

	Uint32			color;
}					t_obj;

typedef struct		s_hit
{
	int				done;
	t_v3			pos;
	t_obj			*obj;
}					t_hit;

typedef struct		s_ray
{
	t_v3			pos;
	t_v3			dir;
	t_v3			screen_pos;
	t_hit			hit;
	t_hit			b_hit;
	double			t;
}					t_ray;

typedef struct		s_rt
{
	SDL_Event		event;
	SDL_Surface		*render;
	SDL_Window		*win;

	int				exit;

	int				w;
	int				h;

	t_cam			camera;

	t_ray			ray;
	t_ray			light;
	t_obj			*objs;

	int				objs_cnt;
}					t_rt;

double				to_rad(double degrees);
double				to_deg(double radians);
Uint32				color_value(Uint32 color, double value);

void				v3_set(t_v3 *v, double newX, double newY, double newZ);
void				v3_reset(t_v3 *v);
int					v3_cmp(t_v3 v1, t_v3 v2);
t_v3				v3_cpy(t_v3 v);
//A supprimer
void				v3_print(t_v3 v, int block);

t_v3				v3_sum(t_v3 v1, t_v3 v2);
t_v3				v3_sub(t_v3 v1, t_v3 v2);
t_v3				v3_mul(t_v3 v, double value);
t_v3				v3_div(t_v3 v, double value);
double				v3_norm(t_v3 v);
t_v3				v3_normalized(t_v3 v);
double				v3_dist(t_v3 v1, t_v3 v2);
t_v3				v3_rot_x(t_v3 v, double a);
t_v3				v3_rot_y(t_v3 v, double a);
t_v3				v3_rot_z(t_v3 v, double a);
t_v3				v3_rot(t_v3 v, double ax, double ay, double az);
t_v3				v3_inv_rot(t_v3 v, double ax, double ay, double az);
double				v3_ang(t_v3 v1, t_v3 v2);

t_hit				hit_empty();
t_hit				hit_copy(t_hit src);
int					hit_closer(t_ray ray, t_hit h1, t_hit h2);

void				ray_reset_hit(t_ray *ray);

void				rtv1_init(t_rt *rt);

void				parse_args(t_rt *rt, int argc, char **argv);

void				sdl_init(t_rt *rt);

void				rtv1_compute(t_rt *rt);

void				rt_sphere(t_obj *obj, t_ray *ray);
t_v3				norm_sphere(t_obj *obj, t_v3 p);
void				rt_cylinder(t_obj *obj, t_ray *ray);
t_v3				norm_cylinder(t_obj *obj, t_v3 p);
void				rt_plane(t_obj *obj, t_ray *ray);
t_v3				norm_plane(t_obj *obj, t_v3 ray_pos, t_v3 ray_hit, int debug);
void				rt_cone(t_obj *obj, t_ray *ray);
t_v3				norm_cone(t_obj *obj, t_v3 p);

void				sdl_loop(t_rt *rt);

void				sdl_events(t_rt *rt);

void				ft_put_pixel(int x, int y, Uint32 c, t_rt *rt);
void				ft_clear_screen(Uint32 color, t_rt *rt);

void				error_handler(int error, t_rt *rt);

void				rtv1_exit(t_rt *rt);

#endif
