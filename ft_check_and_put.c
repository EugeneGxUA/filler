/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:03:40 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/18 14:52:47 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_record_in_list(t_lst **list, int y, int x, t_struct *data)
{
	(*list)->x = x;
	(*list)->y = y;
	(*list)->x_int = data->x_int;
	(*list)->y_int = data->y_int;
	(*list)->n = (t_lst*)malloc(sizeof(t_lst));
	(*list) = (*list)->n;
	(*list)->n = NULL;
	data->p++;
}

static void		ft_check_put(t_struct *data, int i, int j)
{
	int			y;

	data->start_i = i;
	data->start_j = j;
	y = 0;
	while (data->counter < data->stars)
	{
		if (data->field[i + data->y_stars[y]][j + data->x_stars[y]]
				== data->player)
		{
			data->match++;
			data->y_int = i + data->y_stars[y];
			data->x_int = j + data->x_stars[y];
		}
		else if (data->field[i + data->y_stars[y]][j + data->x_stars[y]]
				== data->enemy)
		{
			data->match = 0;
			return ;
		}
		y++;
		data->counter++;
	}
	if (data->match == 1)
		ft_record_in_list(&data->lst, i, j, data);
}

static void		ft_check(t_struct *data)
{
	int			i;
	int			j;

	i = 0;
	while (i <= data->ver_f - data->ver_p)
	{
		j = 0;
		while (j <= data->hor_f - data->hor_p)
		{
			data->match = 0;
			data->counter = 0;
			ft_check_put(data, i, j);
			j++;
		}
		i++;
	}
}

void			ft_check_and_put(t_struct *data)
{
	t_lst		*begin;

	data->p = 0;
	begin = data->lst;
	ft_check(data);
	data->lst = begin;
	if (data->p != 0)
		ft_player_logic(data);
	else
	{
		ft_putnbr_fd(0, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(0, 1);
		ft_putchar_fd('\n', 1);
	}
}
