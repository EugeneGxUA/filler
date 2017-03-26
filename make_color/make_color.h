/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:58:06 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/18 21:33:07 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_COLOR_H
# define MAKE_COLOR_H

# define BUFF_SIZE 100

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <mlx.h>

typedef struct		s_struct
{
	int				ver_f;
	int				hor_f;
	char			**field;
	int				win;
	int				lose;
}					t_struct;

int					main(void);
int					get_next_line(const int fd, char **line);

#endif
