/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:24:34 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/18 15:05:49 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_print(t_cord *wr)
{
	ft_putnbr_fd(wr->y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(wr->x, 1);
	ft_putchar_fd('\n', 1);
}

static int	ft_to_positive(int len)
{
	if (len < 0)
		return (len *= -1);
	else
		return (len);
}

void		ft_put_piece(t_struct *data, t_lst *list, t_cord *wr)
{
	int		y_result;
	int		x_result;
	int		min;
	int		buf;

	min = 2147483647;
	while (list)
	{
		y_result = data->y_enemy - list->y_int;
		y_result = ft_to_positive(y_result);
		x_result = data->x_enemy - list->x_int;
		x_result = ft_to_positive(x_result);
		buf = y_result + x_result;
		if (buf < min)
		{
			min = buf;
			wr->x = list->x;
			wr->y = list->y;
		}
		list = list->n;
	}
	ft_print(wr);
}

void		ft_clear_last_zero(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*last;

	tmp = list;
	while (tmp->n)
	{
		last = tmp;
		tmp = tmp->n;
	}
	free(tmp);
	last->n = NULL;
}

void		ft_player_logic(t_struct *data)
{
	t_lst	*list;
	t_lst	*begin;
	t_cord	*wr;

	wr = (t_cord*)malloc(sizeof(t_cord));
	wr->x = 0;
	wr->y = 0;
	list = data->lst;
	begin = data->lst;
	ft_clear_last_zero(list);
	ft_put_piece(data, begin, wr);
}
