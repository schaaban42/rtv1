/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:24:29 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/20 17:06:25 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ray_reset_hit(t_ray *ray)
{
	ray->hit = (t_hit){0, 0, (t_v3){0, 0, 0}, NULL};
}
