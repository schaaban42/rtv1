/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a2dlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:17:40 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/09 15:01:27 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_a2dlen(const void **array)
{
	int		i;

	i = 0;
	if (array == NULL)
		return (0);
	while (array[i] != NULL)
		i++;
	return (i);
}
