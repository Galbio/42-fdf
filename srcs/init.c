/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:30 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/16 16:00:17 by gakarbou         ###   ########.fr       */
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

void	init_mlx_cam(t_mlx *ds)
{
	ds->cam.rotation[0] = 45;
	ds->cam.rotation[1] = -45;
	ds->cam.rotation[2] = 30;
	ds->cam.rot_grid[0] = 0;
	ds->cam.rot_grid[1] = 0;
	ds->cam.rot_grid[2] = 0;
	ds->cam.off_x = 500;
	ds->cam.off_y = 400;
	ds->cam.zoom = 30;
	if (ds->array.i * 30 > 900)
		ds->cam.zoom = 20;
	if (ds->array.i * 30 > 1300)
		ds->cam.zoom = 5;
	ds->cam.height = 0;
	ds->bon.is_grid = 0;
	ds->bon.draw_lines = 1;
	ds->bon.colors = 1;
}

void	init_mlx(t_mlx *ds, char *file)
{
	parse_map(file, ds);
	ds->mlx_ptr = mlx_init();
	ds->win_ptr = mlx_new_window(ds->mlx_ptr, 1000, 1000, "SdF");
	init_mlx_cam(ds);
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
