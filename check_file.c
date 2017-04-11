/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:16:29 by proso             #+#    #+#             */
/*   Updated: 2016/12/19 19:30:14 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_link(char *str, int j)
{
	int i;
	int link;

	i = 0;
	link = 0;
	while (i < 20)
	{
		if (str[i + j] == '#')
		{
			if ((i + 1) < 20 && str[i + j + 1] == '#')
				link++;
			if ((i - 1) >= 0 && str[i + j - 1] == '#')
				link++;
			if ((i + 5) < 20 && str[i + j + 5] == '#')
				link++;
			if ((i - 5) >= 0 && str[i + j - 5] == '#')
				link++;
		}
		i++;
	}
	if (!(link == 8 || link == 6))
		return (0);
	else
		return (1);
}

static int		check_structure(char *str, int j)
{
	int	i;
	int diese;
	int point;
	int ligne;

	i = 0;
	diese = 0;
	point = 0;
	ligne = 0;
	while (i < 20 && str[i + j] != '\0')
	{
		if (str[i + j] == '.')
			point++;
		if (str[i + j] == '\n')
			ligne++;
		if (str[i + j] == '#')
			diese++;
		i++;
	}
	if (!(point == 12 && ligne == 4 && diese == 4))
		return (0);
	else
		return (1);
}

int				check_file(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (!(check_link(str, j) && check_structure(str, j)))
			return (0);
		i = 19;
		if (str[i + j] == '\n' && str[i + j + 1] == '\0')
			return (1);
		if (str[i + j] == '\n' && str[i + j + 1] == '\n'
				&& (str[i + j + 2] == '.' || str[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
