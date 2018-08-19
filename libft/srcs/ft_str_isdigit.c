/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:17:54 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/30 12:05:27 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isdigit(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
			i++;
		else if (!ft_isdigit((int)s[i]))
			return (0);
		i++;
	}
	return (1);
}
