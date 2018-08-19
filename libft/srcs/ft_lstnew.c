/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:57:25 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 11:16:58 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if ((new_list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new_list->next = NULL;
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		return (new_list);
	}
	if ((new_list->content = (void*)malloc(content_size)) == NULL)
		return (NULL);
	ft_memcpy(new_list->content, content, content_size);
	new_list->content_size = content_size;
	return (new_list);
}
