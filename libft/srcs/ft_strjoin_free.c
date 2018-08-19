/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:24:15 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/19 14:25:05 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (s1 != NULL)
		ft_memdel((void**)&s1);
	return (res);
}
