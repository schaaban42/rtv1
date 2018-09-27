/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:56:05 by schaaban          #+#    #+#             */
/*   Updated: 2018/09/26 21:47:28 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				error_handler(int error, t_rt *rt)
{
	if (error == RT_ERR_MALLOC)
		ft_putendl_fd("error: memory allocation failed", 2);
	else if (error == RT_ERR_SDL_INIT)
		ft_putendl_fd("error: sdl initialization failed", 2);
	else if (error == RT_ERR_ARG)
		ft_putendl_fd("error: wrong argument(s)", 2);
	rtv1_exit(rt);
}
