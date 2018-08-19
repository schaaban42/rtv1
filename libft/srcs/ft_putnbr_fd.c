/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:57:49 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 16:16:39 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		tab[10];
	int		i;

	i = 0;
	while (n != 0 || i == 0)
	{
		tab[i++] = n % 10;
		n = n / 10;
	}
	i = i - 1;
	if (tab[i] < 0)
		ft_putchar_fd('-', fd);
	while (i >= 0)
	{
		ft_putchar_fd(((tab[i] < 0) ? (-tab[i]) : (tab[i])) + '0', fd);
		i--;
	}
}
