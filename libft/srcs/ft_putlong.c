/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:25:58 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 20:26:22 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(long n)
{
	long	tab[19];
	int		i;

	i = 0;
	while (n != 0 || i == 0)
	{
		tab[i++] = n % 10;
		n = n / 10;
	}
	i = i - 1;
	if (tab[i] < 0)
		ft_putchar('-');
	while (i >= 0)
	{
		ft_putchar(((tab[i] < 0) ? (-tab[i]) : (tab[i])) + '0');
		i--;
	}
}
