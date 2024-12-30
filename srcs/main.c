/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:04:34 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/30 14:59:33 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	aled(t_mlx *ds)
{
	(void)ds;
	return (0);
}

void	fdf_draw(t_mlx *ds)
{
	init_points(ds);
	change_x(ds, ds->cam.rotation[0]);
	change_y(ds, ds->cam.rotation[1]);
	change_z(ds, ds->cam.rotation[2]);
	ds->img = init_img(ds->mlx_ptr);
	ds->array.done = ft_calloc(sizeof(char), ds->array.i * ds->array.j);
	draw_array(ds, 0, 0);
	free_array(ds);
	mlx_put_image_to_window(ds->mlx_ptr, ds->win_ptr, ds->img->ptr, 0, 0);
}

int	check_key(int key, t_mlx *ds)
{
	if (key == 65307)
	{
		mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
		return (1);
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
	int		i;

	if (argc != 2)
		return (1);
	init_mlx(&ds, argv[1]);
	i = -1;
	while (++i < (ds.array.j * ds.array.i))
		free(ds.array.array[i]);
	return (free(ds.array.array), 0);
}
