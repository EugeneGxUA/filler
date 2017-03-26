/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:52:38 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/18 14:56:51 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			ft_where_he_is(t_struct *data)
{
	if (data->enemy_start_y < data->ver_f / 2
			&& data->enemy_start_x < data->hor_f / 2)
		data->enemy_position = 1;
	else if (data->enemy_start_y < data->ver_f / 2
			&& data->enemy_start_x > data->hor_f / 2)
		data->enemy_position = 2;
	else if (data->enemy_start_y > data->ver_f / 2
			&& data->enemy_start_x < data->hor_f / 2)
		data->enemy_position = 3;
	else if (data->enemy_start_y > data->ver_f / 2
			&& data->enemy_start_x > data->hor_f / 2)
		data->enemy_position = 4;
}

static void			ft_check_enemy(t_struct *data, int i, int a)
{
	if (data->count_start == 0)
	{
		data->enemy_start_y = i;
		data->enemy_start_x = a;
		data->count_start++;
		ft_where_he_is(data);
	}
	if (data->enemy_count == 0)
	{
		data->y_enemy = i;
		data->x_enemy = a;
		data->enemy_count++;
	}
}

static void			ft_where_am_i(t_struct *data)
{
	if (data->y_start < data->ver_f / 2
			&& data->x_start < data->hor_f / 2)
		data->position = 1;
	else if (data->y_start < data->ver_f / 2
			&& data->x_start > data->hor_f / 2)
		data->position = 2;
	else if (data->y_start > data->ver_f / 2
			&& data->x_start < data->hor_f / 2)
		data->position = 3;
	else if (data->y_start > data->ver_f / 2
			&& data->x_start > data->hor_f / 2)
		data->position = 4;
}

static void			ft_check(char *s, t_struct *data, int i)
{
	int				a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == data->player && data->my_counter == 0)
		{
			data->y_start = i;
			data->x_start = a;
			ft_where_am_i(data);
			data->my_counter++;
			break ;
		}
		if (s[a] == data->enemy)
			ft_check_enemy(data, i, a);
		a++;
	}
}

void				ft_check_position(char **line, t_struct *data, int i)
{
	char			*s;

	s = *line;
	while (ft_isdigit(*s) || *s == ' ')
		s++;
	ft_check(s, data, i);
}
