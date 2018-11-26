/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:37:43 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:42 by schaaban         ###   ########.fr       */
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
# define RT_BASE_WIDTH		100

# define RT_LIGHT_SHADOW	(double)0.02
# define RT_SPHERE_SHINE	(double)0.97
# define RT_CYL_SHINE		(double)0.97
# define RT_CONE_SHINE		(double)0.95
# define RT_PLAN_SHINE		(double)0.999

# define RT_ERR_MALLOC		"error: dynamic allocation failed"
# define RT_ERR_SDL_INIT	"error: sdl initialization failed"
# define RT_ERR_ARG			"usage: ./rtv1 obj1 obj2 obj3 ... (cam) (light)"

# define PLANE_NORM			(t_v3){0, 1, 0}

# define RT_SDL_RMASK		0xff000000
# define RT_SDL_GMASK		0x00ff0000
# define RT_SDL_BMASK		0x0000ff00
# define RT_SDL_AMASK		0x000000ff

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
	char			type;
	t_v3			pos;
	t_v3			rot;
	double			var;
	int				shine;
	Uint32			color;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_hit
{
	int				done;
	double			t;
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
}					t_ray;

typedef struct		s_rt
{
	SDL_Event		event;
	SDL_Surface		*render;
	SDL_Window		*win;

	int				exit;

	int				w;
	int				h;
	
	Uint32			light_color;
	double			light_diff;

	t_cam			camera;

	t_ray			ray;
	t_ray			light;
	t_obj			*objs;
}					t_rt;

double				to_rad(double degrees);
double				to_deg(double radians);
Uint32				color_value(Uint32 color, double value);
Uint32				color_add(Uint32 color1, Uint32 color2);
Uint32				color_sub(Uint32 color1, Uint32 color2);

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

void				obj_add(t_rt *rt, t_obj **list, t_obj new);
void				obj_del(t_obj *list);
void				obj_delone(t_obj **list, t_obj *el);

t_hit				hit_empty();
t_hit				hit_copy(t_hit src);
int					hit_closer(t_ray ray, t_hit h1, t_hit h2);

void				ray_reset_hit(t_ray *ray);

void				rtv1_init(t_rt *rt);

void				parse_args(t_rt *rt, int argc, char **argv);
t_v3				parser_fill_v3(t_rt *rt, char *str, char **split);
void				parser_fill_obj(t_rt *rt, char *str, t_obj *obj);
void				parser_fill_light(t_rt *rt, char *str);
void				parser_fill_cam(t_rt *rt, char *str);

void				sdl_init(t_rt *rt);

void				rtv1_compute(t_rt *rt);

void				light_diffuse(t_rt *rt, Uint32 *color);

void				rt_sphere(t_obj *obj, t_ray *ray);
t_v3				norm_sphere(t_obj *obj, t_v3 p);
void				rt_cylinder(t_obj *obj, t_ray *ray);
t_v3				norm_cylinder(t_obj *obj, t_v3 p);
void				rt_plane(t_obj *obj, t_ray *ray);
t_v3				norm_plane(t_obj *obj, t_v3 ray_pos, t_v3 ray_hit);
void				rt_cone(t_obj *obj, t_ray *ray);
t_v3				norm_cone(t_obj *obj, t_v3 p);

void				sdl_loop(t_rt *rt);

void				sdl_events(t_rt *rt);

void				ft_put_pixel(int x, int y, Uint32 c, t_rt *rt);
void				ft_clear_screen(Uint32 color, t_rt *rt);

void				error_handler(char *error, t_rt *rt);

void				rtv1_exit(t_rt *rt);

#endif
