/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:07:56 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 17:57:16 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(haystack);
	i = 0;
	if (ft_strlen(needle) > len)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0' && i <= len - ft_strlen(needle))
	{
		if (len - i <= 0)
			return (NULL);
		if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
