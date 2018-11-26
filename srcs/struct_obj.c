/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:30:20 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/15 17:14:17 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				obj_add(t_rt *rt, t_obj **list, t_obj new)
{
	t_obj	*dnew;

	if (!list)
		return ;
	if (!(dnew = (t_obj*)ft_memalloc(sizeof(t_obj))))
		error_handler(RT_ERR_MALLOC, rt);
	new.next = *list;
	*dnew = new;
	*list = dnew;
}

void				obj_del(t_obj *list)
{
	t_obj	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_memdel((void**)&tmp);
	}
}

void				obj_delone(t_obj **list, t_obj *el)
{
	t_obj	*last;
	t_obj	*actual;

	if (!list)
		return ;
	actual = *list;
	last = NULL;
	while (actual && actual != el)
	{
		last = actual;
		actual = actual->next;
	}
	if (!actual)
		return ;
	if (last)
		last->next = actual->next;
	else
		*list = actual->next;
	ft_memdel((void**)&actual);
}
