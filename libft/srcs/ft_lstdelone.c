/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:18:47 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 15:48:38 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst != NULL && del != NULL)
	{
		del((*(*alst)).content, (*(*alst)).content_size);
		free((*alst));
		*alst = NULL;
	}
}
