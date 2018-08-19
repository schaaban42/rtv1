/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:52:36 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/09 14:58:24 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_line	*gnl_remain(t_line **remain, int fd)
{
	t_line	*new;
	t_line	*cpy;

	cpy = (*remain);
	while (cpy != NULL)
	{
		if (cpy->fd == fd)
			return (cpy);
		cpy = cpy->next;
	}
	if ((new = (t_line*)malloc(sizeof(t_line))) == NULL)
		return (NULL);
	new->content = NULL;
	new->fd = fd;
	new->next = NULL;
	if (*remain == NULL)
	{
		(*remain) = new;
		return (*remain);
	}
	new->next = *remain;
	*remain = new;
	return (*remain);
}

static void		gnl_free(t_line **start, t_line **remain, char **line)
{
	if (*remain != NULL)
	{
		*start = (*remain)->next;
		(*remain)->content ? ft_memdel((void**)&((*remain)->content)) : 0;
		ft_memdel((void**)remain);
	}
	if (*line != NULL)
		ft_strdel(line);
}

static char		*gnl_split(char *str, char **remain, int *end)
{
	char	*line;
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
		{
			*end = 1;
			if (!(line = ft_strnew(i)))
				return (NULL);
			if (!(*remain = ft_strdup(str + i + 1)))
			{
				line ? ft_strdel(&line) : 0;
				return (NULL);
			}
			if (ft_strlen(*remain) == 0)
				*remain ? ft_memdel((void**)remain) : 0;
			line = ft_strncpy(line, str, i);
			return (line);
		}
	}
	return (line = ft_strdup(str));
}

static int		gnl_read(char **line, t_line *remain, char *buff)
{
	char	*to_add;
	char	*prev_buff;
	int		end;

	end = 0;
	prev_buff = ft_strdup(buff);
	remain->content ? ft_strdel(&(remain->content)) : 0;
	if (!prev_buff)
		return (-1);
	to_add = gnl_split(prev_buff, &(remain->content), &end);
	prev_buff ? ft_strdel(&prev_buff) : 0;
	if (!to_add)
		return (-1);
	*line = ft_strjoin_free(*line, to_add);
	to_add ? free(to_add) : 0;
	return (!(*line) ? -1 : end);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*remain = NULL;
	t_line			*a_rmn;
	char			*buff;
	int				bytes_read;
	int				end;

	end = 0;
	bytes_read = 0;
	if (!line || fd < 0 || !(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	*line = NULL;
	a_rmn = gnl_remain(&remain, fd);
	(a_rmn->content) ? (end = gnl_read(line, a_rmn, a_rmn->content)) : 0;
	while (!end && (bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		end = gnl_read(line, a_rmn, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	buff ? ft_strdel(&buff) : 0;
	if ((end < 0 || bytes_read < 0) || (bytes_read == 0 && !*line))
	{
		(bytes_read == 0 && !*line) ? gnl_free(&remain, &a_rmn, line) : 0;
		return ((end < 0 || bytes_read < 0) ? -1 : 0);
	}
	return (1);
}
