/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:12:39 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/10 17:47:02 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_hit				hit_empty()
{
	return ((t_hit){0, (t_v3){0, 0, 0}, NULL});
}

t_hit				hit_copy(t_hit src)
{
	return ((t_hit){src.done,
		(t_v3){src.pos.x, src.pos.y, src.pos.z}, src.obj});
}

int					hit_closer(t_ray ray, t_hit h1, t_hit h2)
{
	if (v3_dist(ray.pos, h1.pos) < v3_dist(ray.pos, h2.pos))
		return (1);
	return (0);
}
