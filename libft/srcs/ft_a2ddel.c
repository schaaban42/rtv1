/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a2ddel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:27:41 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/19 13:09:09 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_a2ddel(void ***array)
{
	int		i;

	i = 0;
	if (!array || !*array)
		return ;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
	return ;
}
