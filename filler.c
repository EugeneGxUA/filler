/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:35:57 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/18 15:21:45 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_what_player_symbol(char *line, t_struct *data)
{
	int			a;

	a = 0;
	if (*(ft_strchr(line, 'p') + 1) == '1')
	{
		data->player = 'O';
		data->enemy = 'X';
	}
	else
	{
		data->player = 'X';
		data->enemy = 'O';
	}
}

void			ft_record_piece(char **line, t_struct *data, int fd)
{
	int			i;
	char		**s;

	i = 0;
	s = ft_strsplit(*line, ' ');
	data->ver_p = ft_atoi(s[1]);
	data->hor_p = ft_atoi(s[2]);
	data->piece = (char**)malloc(sizeof(char*) * data->ver_p + 1);
	while (get_next_line(fd, line) > 0 && i < data->ver_p)
	{
		ft_check_how_many_stars(line, data);
		data->piece[i++] = ft_strdup(*line);
		free(*line);
		if (i == data->ver_p)
			break ;
	}
	data->piece[i] = NULL;
	ft_check_stars(data);
}

void			ft_record_field(char **line, t_struct *data, int fd)
{
	int			i;
	char		**s;

	i = 0;
	s = ft_strsplit(*line, ' ');
	data->ver_f = ft_atoi(s[1]);
	data->hor_f = ft_atoi(s[2]);
	get_next_line(fd, line);
	data->field = (char**)malloc(sizeof(char*) * data->ver_f + 1);
	while (get_next_line(fd, line) > 0 && i < data->ver_f)
	{
		ft_check_position(line, data, i);
		data->field[i++] = ft_strsub(*line, 4, (size_t)data->hor_f);
		free(*line);
	}
	data->field[i] = NULL;
}

void			ft_to_zero(t_struct *data)
{
	free(data->x_stars);
	free(data->y_stars);
	data->enemy_count = 0;
	data->match = 0;
	data->start_i = 0;
	data->start_j = 0;
	data->y_int = 0;
	data->x_int = 0;
	data->lst->x = 0;
	data->lst->y = 0;
	data->stars = 0;
	data->lst->y_int = 0;
	data->lst->x_int = 0;
	data->lst->n = NULL;
	data->counter = 0;
	data->p = 0;
}

int				main(void)
{
	t_struct	*data;
	t_lst		*list;
	char		*line;
	int			fd;

	fd = 0;
	line = NULL;
	data = (t_struct*)malloc(sizeof(t_struct));
	list = (t_lst*)malloc(sizeof(t_lst));
	list->n = NULL;
	data->lst = list;
	get_next_line(fd, &line);
	if (line[1] == '$')
		ft_what_player_symbol(line, data);
	while (get_next_line(fd, &line) > 0)
	{
		ft_to_zero(data);
		if (line[1] == 'l')
			ft_record_field(&line, data, fd);
		if (line[1] == 'i')
			ft_record_piece(&line, data, fd);
		ft_check_and_put(data);
	}
	return (0);
}
