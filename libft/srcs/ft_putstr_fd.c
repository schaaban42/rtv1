/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:28:38 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/09 14:59:59 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (1)
		if (!s[i++])
			break ;
	write(fd, s, i - 1);
}
