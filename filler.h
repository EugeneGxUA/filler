/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:51:09 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/18 15:21:58 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include <stdlib.h>
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 100

typedef struct		s_lst
{
	int				x;
	int				y;
	int				x_int;
	int				y_int;
	struct s_lst	*n;
}					t_lst;

typedef struct		s_cord
{
	int				x;
	int				y;
	int				min;
}					t_cord;

typedef struct		s_struct
{
	char			player;
	int				y_start;
	int				x_start;
	int				my_counter;
	int				position;
	char			**field;
	int				ver_f;
	int				hor_f;
	char			**piece;
	int				ver_p;
	int				hor_p;
	int				stars;
	int				*x_stars;
	int				*y_stars;
	char			enemy;
	int				y_enemy;
	int				x_enemy;
	int				enemy_count;
	int				enemy_start_x;
	int				enemy_start_y;
	int				count_start;
	int				enemy_position;
	int				match;
	int				start_i;
	int				start_j;
	int				y_centr;
	int				x_centr;
	int				y_int;
	int				x_int;
	int				counter;
	int				p;
	t_lst			*lst;

}					t_struct;

int					get_next_line(const int fd, char **line);
void				ft_check_and_put(t_struct *data);
void				ft_check_position(char **line, t_struct *data, int i);
void				ft_check_stars(t_struct *data);
void				ft_check_how_many_stars(char **line, t_struct *data);
int					main(void);
void				ft_player_logic(t_struct *data);

#endif
