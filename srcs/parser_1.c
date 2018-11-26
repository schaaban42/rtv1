/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:08:35 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 14:40:48 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int			s_check_arg(t_rt *rt, char *str)
{
	t_obj		new_obj;

	new_obj = (t_obj){'s', (t_v3){0, 0, 0}, (t_v3){0, 0, 0}, 0, 0, 0, NULL};
	if (ft_strlen(str) < 1)
		return (0);
	if (str[0] == 'k')
		parser_fill_cam(rt, str);
	else if (str[0] == 'l')
		parser_fill_light(rt, str);
	else if (str[0] == 'c' || str[0] == 'p' || str[0] == 'o' || str[0] == 's')
	{
		parser_fill_obj(rt, str, &new_obj);
		obj_add(rt, &(rt->objs), new_obj);
	}
	else
		return (0);
	return (1);
}

void				parse_args(t_rt *rt, int argc, char **argv)
{
	int		i;
	int		cam_cnt;
	int		light_cnt;

	i = 0;
	cam_cnt = 0;
	light_cnt = 0;
	while (++i < argc)
	{
		if (!s_check_arg(rt, argv[i]))
			error_handler(RT_ERR_ARG, rt);
		cam_cnt += (argv[i][0] == 'k') ? 1 : 0;
		light_cnt += (argv[i][0] == 'l') ? 1 : 0;
	}
	if (cam_cnt > 1 || light_cnt > 1)
		error_handler(RT_ERR_ARG, rt);
}
