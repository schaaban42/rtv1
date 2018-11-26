/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_math_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 12:56:30 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/22 14:48:08 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				v3_norm(t_v3 v)
{
	return (sqrt(
		(v.x * v.x)
		+ (v.y * v.y)
		+ (v.z * v.z)));
}

t_v3				v3_normalized(t_v3 v)
{
	return (v3_div(v, v3_norm(v)));
}

double				v3_dist(t_v3 v1, t_v3 v2)
{
	return (v3_norm(v3_sub(v2, v1)));
}

double				v3_ang(t_v3 v1, t_v3 v2)
{
	double		cosa;

	v1 = v3_normalized(v1);
	v2 = v3_normalized(v2);
	cosa = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	return (cosa);
}
