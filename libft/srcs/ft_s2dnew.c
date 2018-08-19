/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s2dnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 01:12:59 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/20 01:14:39 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_s2dnew(size_t size)
{
	char	**res;
	size_t	i;

	i = 0;
	if ((res = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	while (i <= size)
		res[i++] = NULL;
	return (res);
}
