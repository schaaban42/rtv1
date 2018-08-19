/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:09:32 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 15:50:50 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*first_result;
	t_list	*tmp;

	if (((result = (t_list*)malloc(sizeof(t_list))) == NULL) ||
		(lst == NULL || f == NULL))
		return (NULL);
	first_result = result;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			tmp = f(lst);
			result->content = tmp->content;
			result->content_size = tmp->content_size;
			lst = lst->next;
			if (!(result->next = ft_lstnew(NULL, 0)))
				return (NULL);
			result = result->next;
		}
		tmp = f(lst);
		result->content = tmp->content;
		result->content_size = tmp->content_size;
	}
	return (first_result);
}
