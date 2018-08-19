/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:48:11 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/09 10:11:14 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s_s1;
	char	*s_s2;

	i = 0;
	s_s1 = (char*)s1;
	s_s2 = (char*)s2;
	while (i < n)
	{
		if (s_s1[i] != s_s2[i])
			return ((int)((unsigned char)s_s1[i] - (unsigned char)s_s2[i]));
		i++;
	}
	return (0);
}
