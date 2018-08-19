/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:54:51 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/09 09:58:43 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*s_mem;
	size_t	i;

	i = 0;
	if ((mem = malloc(size)) == NULL)
		return (NULL);
	s_mem = (char*)mem;
	while (i < size)
		s_mem[i++] = 0;
	return (mem);
}
