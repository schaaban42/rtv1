/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:02:59 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/09 15:00:38 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*res;
	int		tab[32];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (n != 0 || i == -1)
	{
		tab[++i] = n % 10;
		n /= 10;
	}
	if (!(res = (char*)malloc(sizeof(char) *
		(i + ((tab[i] < 0) ? 3 : 2)))))
		return (NULL);
	if (tab[i++] < 0)
		res[j++] = '-';
	while (--i >= 0)
	{
		tab[i] = (tab[i] < 0) ? -tab[i] : tab[i];
		res[j++] = tab[i] + '0';
	}
	res[j] = '\0';
	return (res);
}
