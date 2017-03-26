# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaragul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 14:58:07 by egaragul          #+#    #+#              #
#    Updated: 2017/03/18 15:35:43 by egaragul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = filler.c\
	  ft_check_and_put.c\
	  ft_check_position.c\
	  ft_check_stars.c\
	  ft_player_logic.c\
	  get_next_line.c
GG = $(SRC:.c=.o)
HEAD = filler.h
FLAG = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(@GG)
	@make -C libft
	@gcc $(FLAG) $(SRC)
	@gcc -o $(NAME) $(GG) libft/libft.a

clean:
	@rm -f *.o
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all
