/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:08:35 by schaaban          #+#    #+#             */
/*   Updated: 2018/09/27 03:05:59 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int			s_check_arg(t_rt *rt, char *str)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = ft_strsplit(str, '|')))
		error_handler(RT_ERR_MALLOC, rt);
	while (tab[++i])
	{

	}
	ft_a2ddel((void***)&tab);
	return (1);
}

void				parse_args(t_rt *rt, int argc, char **argv)
{
	int		i;

	i = 0;
	rt->objs_cnt = argc - 1;
	while (++i < argc)
	{
		if (!s_check_arg(rt, argv[i]))
			error_handler(RT_ERR_ARG, rt);
	}
}
