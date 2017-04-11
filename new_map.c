/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:48:54 by mlegeay           #+#    #+#             */
/*   Updated: 2016/12/19 20:03:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_size(t_tetra *begin_list)
{
	int		size;
	int		tetra;
	t_tetra *current;

	current = begin_list;
	tetra = 0;
	size = 0;
	while (current)
	{
		tetra++;
		current = current->next;
	}
	while (size * size < tetra * 4)
		size++;
	return (size);
}

void	remove_symbol(char symbol, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == symbol)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
}

char	**gen_empty_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (size + 2))))
			return (NULL);
		ft_memset(map[i], '.', size);
		map[i][size] = '\n';
		map[i][size + 1] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
