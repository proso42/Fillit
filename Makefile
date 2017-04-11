# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:34:33 by mlegeay           #+#    #+#              #
#    Updated: 2017/03/30 11:59:09 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re

NAME	= fillit

SRC		= main.c \
		  gen_list.c \
		  read_file.c \
		  new_map.c \
		  check_file.c \
		  solve.c \
		  ft_putstr_fd.c \
		  ft_memset.c \
		  ft_memdel.c \
		  ft_strdup.c \
		  ft_strnew.c \
		  ft_strjoin.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ	= $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
