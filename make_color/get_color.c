/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:31:31 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/18 21:31:34 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_color.h"

static void			ft_record_field(char **line, t_struct *data, int fd)
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
		data->field[i++] = ft_strsub(*line, 4, (size_t)data->hor_f);
		free(*line);
	}
	data->field[i] = NULL;
}

static void			ft_change_color(t_struct *data)
{
	int				i;
	int				j;

	i = 0;
	while (data->field[i] != NULL)
	{
		j = 0;
		while (data->field[i][j] != '\0')
		{
			if (data->field[i][j] == 'X')
				printf("\e[31m*\e[01m");
			else if (data->field[i][j] == '.')
				printf("\e[33m.\e[01m");
			else if (data->field[i][j] == 'O')
				printf("\e[34m^\e[01m");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n\n\n\n");
}

void				ft_winer(t_struct *data, char **line)
{
	char			**s;
	char			**str;

	s = ft_strsplit(*line, ' ');
	data->win = ft_atoi(s[3]);
	get_next_line(0, line);
	str = ft_strsplit(*line, ' ');
	data->lose = ft_atoi(s[3]);
}

void				ft_for_img(t_struct *data)
{
	void			*mlx;
	void			*w;
	void			*img;
	int				x;
	int				y;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, "winner.xpm", &x, &y);
	if (data->win > data->lose)
	{
		w = mlx_new_window(mlx, 400, 323, "FILLER");
		mlx_put_image_to_window(mlx, w, img, 0, 0);
		mlx_string_put(mlx, w, 320, 20, 0x000000, "O WIN");
		mlx_loop(mlx);
	}
	else
	{
		w = mlx_new_window(mlx, 400, 323, "filler");
		mlx_put_image_to_window(mlx, w, img, 0, 0);
		mlx_string_put(mlx, w, 320, 20, 0x000000, "X WIN");
		mlx_loop(mlx);
	}
}

int					main(void)
{
	t_struct		*data;
	char			*line;
	int				fd;

	fd = 0;
	line = NULL;
	data = (t_struct*)malloc(sizeof(t_struct));
	get_next_line(fd, &line);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[1] == 'l')
		{
			ft_record_field(&line, data, fd);
			ft_change_color(data);
		}
		if (line[1] == '=')
		{
			ft_winer(data, &line);
			ft_for_img(data);
		}
	}
	return (0);
}
