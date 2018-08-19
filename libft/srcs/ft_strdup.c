/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:01:58 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/09 14:59:23 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	while (1)
		if (!s1[i++])
			break ;
	if ((str = (char*)malloc(sizeof(char) * (i))) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
