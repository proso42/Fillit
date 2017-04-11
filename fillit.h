/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:03:28 by mlegeay           #+#    #+#             */
/*   Updated: 2017/03/30 11:13:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# define BUF_SIZE 200

typedef struct		s_tetra
{
	char			symbol;
	int				y[4];
	int				x[4];
	struct s_tetra	*next;
}					t_tetra;

char				*read_file(char *file);
int					get_size_buf(char *buf);
int					test_map(char *str);
t_tetra				*gen_list(char *buf, int size);
char				**gen_empty_map(int size);
void				print_map(char **map);
void				remove_symbol(char symbol, char **map);
int					solve(char **map, t_tetra *begin_list);
int					check_file(char *str);
int					get_size(t_tetra *begin_list);
void				ft_list_clear(t_tetra **begin_list);

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strdup(char const *str);
void				ft_memdel(void **app);
void				ft_memset(char const *str, int c, size_t len);
#endif
