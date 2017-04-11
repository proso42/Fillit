/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:42:51 by mlegeay           #+#    #+#             */
/*   Updated: 2016/12/19 20:38:52 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_clear(t_tetra **begin_list)
{
	t_tetra	*curent;
	t_tetra	*previous;

	curent = *begin_list;
	previous = curent;
	while (curent)
	{
		curent = curent->next;
		free(previous);
		previous = curent;
	}
	*begin_list = 0;
}

int		get_size_buf(char *buf)
{
	int		i;
	int		size;

	i = 0;
	size = 1;
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			size++;
		i++;
	}
	return (size);
}

char	*read_file(char *file)
{
	int		fd;
	int		ret;
	char	*map;
	char	*cpy;
	char	buffer[10 + 1];

	map = ft_strnew(1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buffer, 10)))
	{
		if (ret == -1)
			return (NULL);
		buffer[ret] = '\0';
		cpy = ft_strdup(map);
		free(map);
		map = ft_strjoin(cpy, buffer);
		free(cpy);
	}
	close(fd);
	if (!map[0])
		return (NULL);
	return (map);
}
