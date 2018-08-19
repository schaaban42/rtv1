/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:37:31 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/09 15:00:50 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa_base(int n, int base)
{
	char	*res;
	int		tab[32];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (n != 0 || i == -1)
	{
		tab[++i] = n % base;
		n /= base;
	}
	if (!(res = (char*)malloc(sizeof(char) *
		(i + ((tab[i] < 0 && base == 10) ? 3 : 2)))))
		return (NULL);
	if (tab[i++] < 0 && base == 10)
		res[j++] = '-';
	while (--i >= 0)
	{
		tab[i] = (tab[i] < 0) ? -tab[i] : tab[i];
		res[j++] = tab[i] + ((tab[i] > 9) ? ('A' - 10) : '0');
	}
	res[j] = '\0';
	return (res);
}
