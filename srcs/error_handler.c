/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:56:05 by schaaban          #+#    #+#             */
/*   Updated: 2018/08/02 11:47:09 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				error_handler(int error, t_rt *rt)
{
	if (error == RT_ERR_MALLOC)
		ft_putendl_fd("error: memory allocation failed", 2);
	rtv1_exit(rt);
}
