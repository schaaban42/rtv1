/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:53:51 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/18 19:32:38 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;

	if (src == dst)
		return (dst);
	s_dst = (unsigned char*)dst;
	s_src = (unsigned char*)src;
	while (n-- > 0)
		*s_dst++ = *s_src++;
	return (dst);
}
