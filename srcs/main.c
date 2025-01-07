/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:04:34 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/07 01:41:45 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_ds(t_mlx *ds)
{
	int	i;

	i = -1;
	mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
	mlx_destroy_display(ds->mlx_ptr);
	free(ds->mlx_ptr);
	while (++i < (ds->array.j * ds->array.i))
		free(ds->array.array[i]);
	free(ds->array.height);
	free(ds->array.array);
	free(ds->array.colors);
	i = -1;
	while (++i < ds->array.j)
		free(ds->array.map[i]);
	free(ds->array.map);
}

void	fdf_draw(t_mlx *ds)
{
	change_x(ds, ds->cam.rotation[0], ds->cam.rotation[1], ds->cam.rotation[2]);
	ds->img = init_img(ds->mlx_ptr);
	ds->array.done = ft_calloc(sizeof(char), ds->array.i * ds->array.j);
	draw_array(ds, 0, 0);
	free(ds->array.done);
	mlx_put_image_to_window(ds->mlx_ptr, ds->win_ptr, ds->img->ptr, 0, 0);
}

int	check_key(int key, t_mlx *ds)
{
	if (key == 65307)
	{
		free_ds(ds);
		exit(0);
	}
	else if (key == 'u' || key == 'j')
		ds->cam.rotation[0] += 1 - (2 * (key == 'j'));
	else if (key == 'i' || key == 'k')
		ds->cam.rotation[1] += 1 - (2 * (key == 'k'));
	else if (key == 'o' || key == 'l')
		ds->cam.rotation[2] += 1 - (2 * (key == 'l'));
	else if (key == 's' || key == 'w')
		ds->cam.off_y += 10 - (20 * (key == 'w'));
	else if (key == 'd' || key == 'a')
		ds->cam.off_x += 10 - (20 * (key == 'a'));
	else if (key == '-' || key == '=')
		ds->cam.zoom += 1 - (2 * (key == '-'));
	else if (key == '1' || key == '2')
		ds->cam.height += 1 - (2 * (key == '2'));
	else if (key == 32)
		return (0);
	else
		return (1);
	return (0);
}

int	fdf(int key, t_mlx *ds)
{
	if (ds->img)
	{
		mlx_destroy_image(ds->mlx_ptr, ds->img->ptr);
		free(ds->img);
		ds->img = NULL;
	}
	if (check_key(key, ds))
		return (0);
	ds->cam.zoom = ft_max(ds->cam.zoom, 0);
	fdf_draw(ds);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	ds;

	if (argc != 2)
		return (1);
	init_mlx(&ds, argv[1]);
	return (0);
}
