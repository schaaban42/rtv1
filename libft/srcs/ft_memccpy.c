/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:37:56 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/10 13:50:34 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;
	size_t			i;

	i = 0;
	s_dst = (unsigned char*)dst;
	s_src = (unsigned char*)src;
	while (i < n)
	{
		s_dst[i] = s_src[i];
		if (s_src[i] == (unsigned char)c)
			return (&s_dst[i + 1]);
		i++;
	}
	return (NULL);
}
