/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:28:52 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/30 13:30:51 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*i;
	t_list	*i_next;

	if (*alst == NULL || del == NULL)
		return ;
	i = (*alst);
	i_next = (*alst)->next;
	while (i_next != NULL)
	{
		i_next = i->next;
		del(i->content, i->content_size);
		free(i);
		i = i_next;
	}
	*alst = NULL;
}
