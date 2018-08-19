/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:06:48 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 13:12:37 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (s == NULL)
		return (NULL);
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strncpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
