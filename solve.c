/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:35:42 by proso             #+#    #+#             */
/*   Updated: 2016/12/19 20:03:52 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_y_max(char **map, t_tetra *tetra, int pos_y)
{
	int		y_max;

	y_max = 0;
	while (map[y_max])
		y_max++;
	if (pos_y + ((tetra->y)[3]) - (tetra->y)[0] >= y_max)
		return (0);
	else
		return (1);
}

static int		insert(char **map, t_tetra *tetra, int pos_y, int pos_x)
{
	if (!(check_y_max(map, tetra, pos_y)))
		return (0);
	if (map[pos_y][pos_x] != '.')
		return (0);
	if (map[pos_y + ((tetra->y)[1]) - (tetra->y)[0]][pos_x
			+ ((tetra->x)[1]) - (tetra->x)[0]] != '.')
		return (0);
	if (map[pos_y + ((tetra->y)[2]) - (tetra->y)[0]][pos_x
			+ ((tetra->x)[2]) - (tetra->x)[0]] != '.')
		return (0);
	if (map[pos_y + ((tetra->y)[3]) - (tetra->y)[0]][pos_x
			+ ((tetra->x)[3]) - (tetra->x)[0]] != '.')
		return (0);
	map[pos_y][pos_x] = tetra->symbol;
	map[pos_y + ((tetra->y)[1]) - (tetra->y)[0]][pos_x
		+ ((tetra->x)[1]) - (tetra->x)[0]] = tetra->symbol;
	map[pos_y + ((tetra->y)[2]) - (tetra->y)[0]][pos_x
		+ ((tetra->x)[2]) - (tetra->x)[0]] = tetra->symbol;
	map[pos_y + ((tetra->y)[3]) - (tetra->y)[0]][pos_x
		+ ((tetra->x)[3]) - (tetra->x)[0]] = tetra->symbol;
	return (1);
}

static int		update_yx(char **map, int *pos_y, int *pos_x)
{
	if (map[*pos_y][*pos_x + 1] == '\n')
	{
		*pos_x = 0;
		if (map[*pos_y + 1])
			*pos_y += 1;
		else
			return (0);
	}
	else
		*pos_x += 1;
	return (1);
}

static int		trying(char **map, t_tetra *current, int pos_y, int pos_x)
{
	if (!current)
		return (1);
	while (map[pos_y][pos_x])
	{
		if (insert(map, current, pos_y, pos_x))
		{
			if (!trying(map, current->next, 0, 0))
			{
				remove_symbol(current->symbol, map);
				if (!(update_yx(map, &pos_y, &pos_x)))
					return (0);
			}
			else
				return (1);
		}
		else
		{
			if (!(update_yx(map, &pos_y, &pos_x)))
				return (0);
		}
	}
	return (0);
}

int				solve(char **map, t_tetra *begin_list)
{
	int		size;

	size = get_size(begin_list);
	while (!(trying(map, begin_list, 0, 0)))
	{
		size++;
		map = gen_empty_map(size);
	}
	print_map(map);
	return (1);
}
