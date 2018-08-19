/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:45:18 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/28 17:18:17 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	split_isword(char const *str, int index, char c)
{
	if (index == 0)
		return (0);
	if ((str[index] == c || str[index] == '\0') &&
		(str[index - 1] != c && str[index - 1] != '\0'))
		return (1);
	return (0);
}

static int	split_count(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (split_isword(str, i, c))
			count++;
		i++;
		if (str[i] == '\0' && split_isword(str, i, c))
			count++;
	}
	return (count);
}

static char	*split_getword(char const *str, int index, char c)
{
	char	*word;
	int		i;
	int		j;

	i = index - 1;
	j = 0;
	while (i >= 0 && str[i] != c && str[i] != '\0')
		i--;
	i++;
	if ((word = (char*)malloc(sizeof(char) * (index - i + 1))) == NULL)
		return (NULL);
	while (j < index - i)
	{
		word[j] = str[j + i];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	count = split_count(s, c);
	if ((tab = (char**)malloc(sizeof(char*) * (count + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (split_isword(s, i, c))
			if (!(tab[j++] = split_getword(s, i, c)))
				ft_a2ddel((void***)&tab);
		i++;
		if (s[i] == '\0' && split_isword(s, i, c))
			if (!(tab[j++] = split_getword(s, i, c)))
				ft_a2ddel((void***)&tab);
	}
	tab[j] = 0;
	return (tab);
}
