# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaragul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 20:58:22 by egaragul          #+#    #+#              #
#    Updated: 2017/03/18 21:29:38 by egaragul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make re -C libft/
gcc -o make_color -Wall -Wextra -Werror get_color.c get_next_line.c libft/libft.a -lmlx -framework OpenGL -framework AppKit
