/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:31:59 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/10 15:46:00 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;
	int				i;

	i = 0;
	s_dst = (unsigned char*)dst;
	s_src = (unsigned char*)src;
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			s_dst[i] = s_src[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(s_dst, s_src, len);
	}
	return (s_dst);
}
