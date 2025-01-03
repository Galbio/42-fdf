/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:30 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/02 15:22:03 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points(t_mlx *ds)
{
	t_point	**map;
	int		i;

	map = ft_calloc(sizeof(t_point *), ds->array.j);
	if (!map)
		return ;
	i = -1;
	while (++i < ds->array.j)
		map[i] = ft_calloc(sizeof(t_point), ds->array.i);
	ds->array.map = map;
	fill_map(ds);
}

void	init_mlx(t_mlx *ds, char *file)
{
	parse_map(file, ds);
	ds->mlx_ptr = mlx_init();
	ds->win_ptr = mlx_new_window(ds->mlx_ptr, 1000, 1000, "SdF");
	ds->cam.rotation[0] = 45;
	ds->cam.rotation[1] = -36;
	ds->cam.rotation[2] = 30;
	ds->cam.off_x = 500;
	ds->cam.off_y = 400;
	ds->cam.zoom = 30;
	if (ds->array.i * 30 > 900)
		ds->cam.zoom = 20;
	if (ds->array.i * 30 > 1300)
		ds->cam.zoom = 5;
	ds->cam.height = 0;
	fdf_draw(ds);
	mlx_hook(ds->win_ptr, 2, 1L << 0, fdf, ds);
	mlx_mouse_hook(ds->win_ptr, check_mouse, ds);
	mlx_hook(ds->win_ptr, 17, 0, close_fdf, ds);
	mlx_loop_hook(ds->mlx_ptr, &aled, ds);
	mlx_loop(ds->mlx_ptr);
	mlx_destroy_display(ds->mlx_ptr);
	free(ds->mlx_ptr);
}

void	*init_img(void *mlx_ptr)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	if (!res)
		return (NULL);
	res->ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	res->addr = mlx_get_data_addr(res->ptr, &(res)->bits_per_pixel,
			&(res)->size_line, &(res)->endian);
	return (res);
}

void	parse_map(char *filename, t_mlx *ds)
{
	int		fd;
	int		len;
	char	*joined_str;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	len = 0;
	joined_str = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len++;
		joined_str = ft_securejoin(joined_str, line, 1);
		free(line);
	}
	ds->array.array = ft_split(ft_str_replace_char(joined_str, '\n', ' '), ' ');
	ds->array.j = len;
	ds->array.i = array_len(ds->array.array) / ds->array.j;
	init_height(ds);
	free(joined_str);
}

void	fill_map(t_mlx *ds)
{
	int		i;
	int		j;
	int		height;

	height = ds->array.i;
	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			ds->array.map[j][i].x = (i - (ds->array.i / 2)) * ds->cam.zoom;
			ds->array.map[j][i].y = (j - (ds->array.j / 2)) * ds->cam.zoom;
			ds->array.map[j][i].z = ds->array.height[(j * height) + i]
				* ((ds->cam.zoom + (ds->cam.height * 1)) / 1);
			ds->array.map[j][i].color = get_color(ds, j, i);
		}
	}
}
