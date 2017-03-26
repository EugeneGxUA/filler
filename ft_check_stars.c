/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:17:57 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/17 16:43:26 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_check_how_many_stars(char **line, t_struct *data)
{
	int			a;

	a = 0;
	while ((*line)[a] != '\0')
	{
		if ((*line)[a] == '*')
			data->stars++;
		a++;
	}
}

void			ft_check_stars(t_struct *data)
{
	int			i;
	int			j;
	int			a;

	i = 0;
	a = 0;
	data->x_stars = (int*)malloc(sizeof(int) * data->stars);
	data->y_stars = (int*)malloc(sizeof(int) * data->stars);
	while (data->piece[i] != NULL)
	{
		j = 0;
		while (data->piece[i][j] != '\0')
		{
			if (data->piece[i][j] == '*')
			{
				data->y_stars[a] = i;
				data->x_stars[a] = j;
				a++;
			}
			j++;
		}
		i++;
	}
}
