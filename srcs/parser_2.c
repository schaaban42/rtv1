/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:39:08 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 14:41:16 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v3				parser_fill_v3(t_rt *rt, char *str, char **split)
{
	t_v3	vec;
	char	**split_str;

	if (!(split_str = ft_strsplit(str, ',')))
	{
		ft_a2ddel((void***)&split);
		error_handler(RT_ERR_MALLOC, rt);
	}
	if (ft_a2dlen((const void**)split_str) != 3)
	{
		ft_a2ddel((void***)&split);
		error_handler(RT_ERR_ARG, rt);
	}
	vec = (t_v3){(double)ft_atoi(split_str[0]),
		(double)ft_atoi(split_str[1]), (double)ft_atoi(split_str[2])};
	ft_a2ddel((void***)&split_str);
	return (vec);
}

void				parser_fill_obj(t_rt *rt, char *str, t_obj *obj)
{
	char	**split;
	int		plan;

	plan = (str[0] == 'p') ? 1 : 0;
	if (!(split = ft_strsplit(str, '|')))
		error_handler(RT_ERR_MALLOC, rt);
	if (ft_a2dlen((const void**)split) != (6 - plan))
	{
		ft_a2ddel((void***)&split);
		error_handler(RT_ERR_ARG, rt);
	}
	obj->type = split[0][0];
	obj->pos = parser_fill_v3(rt, split[1], split);
	obj->rot = parser_fill_v3(rt, split[2], split);
	if (!plan)
		obj->var = (double)ft_atoi(split[3]);
	obj->var = (obj->var < 1) ? 1 : obj->var;
	if (str[0] == 'o')
		obj->var = (obj->var > 45) ? 45 : obj->var;
	obj->shine = ft_atoi(split[4 - plan]);
	obj->shine = (obj->shine < (double)0) ? 0 : obj->shine;
	obj->color = ft_atoi_base(split[5 - plan], 16) | 0xff000000;
	ft_a2ddel((void***)&split);
}

void				parser_fill_light(t_rt *rt, char *str)
{
	char	**split;

	if (!(split = ft_strsplit(str, '|')))
		error_handler(RT_ERR_MALLOC, rt);
	if (ft_a2dlen((const void**)split) != 4)
	{
		ft_a2ddel((void***)&split);
		error_handler(RT_ERR_ARG, rt);
	}
	rt->light.pos = parser_fill_v3(rt, split[1], split);
	rt->light_diff = ((double)ft_atoi(split[2])/(double)100);
	rt->light_diff = (rt->light_diff < 0) ? (double)0 : rt->light_diff; 
	rt->light_diff = (rt->light_diff > 1) ? (double)1 : rt->light_diff;
	rt->light_color = ft_atoi_base(split[3], 16) | 0xff000000; 
	ft_a2ddel((void***)&split);
}

void				parser_fill_cam(t_rt *rt, char *str)
{
	char	**split;

	if (!(split = ft_strsplit(str, '|')))
		error_handler(RT_ERR_MALLOC, rt);
	if (ft_a2dlen((const void**)split) != 5)
	{
		ft_a2ddel((void***)&split);
		error_handler(RT_ERR_ARG, rt);
	}
	rt->camera.pos = parser_fill_v3(rt, split[1], split);
	rt->camera.rot = parser_fill_v3(rt, split[2], split);
	rt->w = ft_atoi(split[3]);
	rt->h = ft_atoi(split[4]);
	rt->w = (rt->w < 100) ? 100 : rt->w;
	rt->h = (rt->h < 100) ? 100 : rt->h;
	rt->w = (rt->w > 1600) ? 1600 : rt->w;
	rt->h = (rt->h > 900) ? 900 : rt->h; 
	ft_a2ddel((void***)&split);
}
