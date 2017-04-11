/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:24:49 by proso             #+#    #+#             */
/*   Updated: 2016/12/19 13:26:06 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init_coordonnee(t_tetra *tetra, int position, char *buf)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (k < 4)
	{
		if (buf[position] == '#')
		{
			(tetra->y)[k] = i;
			(tetra->x)[k] = j;
			k++;
		}
		position++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
}

static void		add_tetra(t_tetra **begin_list, t_tetra *tetra)
{
	t_tetra *current;

	current = *begin_list;
	if (!current)
	{
		*begin_list = tetra;
		tetra->next = NULL;
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = tetra;
		tetra->next = NULL;
	}
}

t_tetra			*gen_list(char *buf, int size)
{
	t_tetra		*current;
	t_tetra		*begin_list;
	int			position;

	position = 0;
	begin_list = NULL;
	while (size)
	{
		if (!(current = (t_tetra*)malloc(sizeof(t_tetra))))
			return (NULL);
		init_coordonnee(current, position, buf);
		current->symbol = (position / 21) + 'A';
		add_tetra(&begin_list, current);
		size--;
		position += 21;
		current = current->next;
	}
	return (begin_list);
}
