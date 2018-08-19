/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:38:32 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 11:59:35 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst == NULL)
	{
		(*alst) = new;
		return ;
	}
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
