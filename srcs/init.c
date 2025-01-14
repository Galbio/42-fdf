/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:30 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/13 22:04:02 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points(t_mlx *ds)
{
	t_point	**map;
	int		i;

	map = malloc(sizeof(t_point *) * ds->array.j);
	if (!map)
		return ;
	i = -1;
	while (++i < ds->array.j)
		map[i] = malloc(sizeof(t_point) * ds->array.i);
	ds->array.map = map;
	fill_colors(ds);
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
	ds->is_grid = 0;
	init_points(ds);
	fdf_draw(ds);
	mlx_hook(ds->win_ptr, 2, 1L << 0, fdf, ds);
	mlx_hook(ds->win_ptr, 4, 1L << 2, check_mouse, ds);
	mlx_hook(ds->win_ptr, 17, 0, close_fdf, ds);
	mlx_loop(ds->mlx_ptr);
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

void	fill_array(char *filename, t_mlx *ds, size_t size)
{
	char	*buffer;
	int		fd;

	buffer = malloc((size + 1) * sizeof(char));
	fd = open(filename, O_RDONLY);
	read(fd, buffer, size);
	buffer[size] = 0;
	ds->array.j = ft_count_char(buffer, '\n');
	ds->array.array = ft_split(ft_str_replace_char(buffer, '\n', ' '), ' ');
	ds->array.i = array_len(ds->array.array) / ds->array.j;
	free(buffer);
}

void	parse_map(char *filename, t_mlx *ds)
{
	size_t	size[2];
	int		fd;
	char	buffer[2048];

	size[1] = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (1)
	{
		size[0] = read(fd, buffer, sizeof(buffer));
		if (!size[0])
			break ;
		size[1] += size[0];
	}
	close(fd);
	fill_array(filename, ds, size[1]);
	init_height(ds);
}
