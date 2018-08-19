/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:36:35 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 15:45:48 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if ((result = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(s[i]);
		i++;
	}
	return (result);
}
