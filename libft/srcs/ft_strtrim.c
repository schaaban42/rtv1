/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:03:35 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 13:08:48 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	j++;
	if (i == ft_strlen(s) && j == 0)
	{
		if ((result = ft_strnew(0)) == NULL)
			return (NULL);
		return (result);
	}
	if ((result = ft_strnew(j - i)) == NULL)
		return (NULL);
	ft_strncpy(result, s + i, j - i);
	return (result);
}
