/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:43:46 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/10 14:41:13 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_str;

	i = 0;
	s_str = (unsigned char*)s;
	while (i < n)
	{
		if (s_str[i] == (unsigned char)c)
			return (&s_str[i]);
		i++;
	}
	return (NULL);
}
