/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:32:11 by mlegeay           #+#    #+#             */
/*   Updated: 2017/03/30 11:12:50 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*buf;
	char	**map;
	t_tetra *begin_list;

	if (argc != 2)
	{
		ft_putstr_fd("usage : fillit sourcefile\n", 1);
		return (0);
	}
	if (!(buf = read_file(argv[1])))
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (check_file(buf) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	begin_list = gen_list(buf, get_size_buf(buf));
	map = gen_empty_map(get_size(begin_list));
	solve(map, begin_list);
	ft_list_clear(&begin_list);
	ft_memdel((void**)map);
	return (0);
}
