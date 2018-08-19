/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:27:06 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/09 15:00:09 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (1)
		if (!s[i++])
			break ;
	write(1, s, i - 1);
}
