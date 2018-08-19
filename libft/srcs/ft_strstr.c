/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:58:51 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/10 15:21:56 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
