/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:04:34 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/16 15:40:36 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw(t_mlx *ds)
{
	if (!ds->bon.is_grid)
		change_x(ds, ds->cam.rotation);
	else
		change_x(ds, ds->cam.rot_grid);
	ds->img = init_img(ds->mlx_ptr);
	ds->array.done = ft_calloc(sizeof(char), ds->array.i * ds->array.j);
	draw_array(ds, 0, 0);
	free(ds->array.done);
	mlx_put_image_to_window(ds->mlx_ptr, ds->win_ptr, ds->img->ptr, 0, 0);
}

int	check_key2(int key, t_mlx *ds)
{
	if (key == 'p')
		ds->bon.draw_lines ^= 1;
	else if (key == 'c')
		ds->bon.colors ^= 1;
	else
		return (1);
	return (0);
}

int	check_key(int key, t_mlx *ds)
{
	if (key == 65307 || key == 32)
		return (-1 + (key == 32));
	else if (key == 65507)
		ds->bon.is_grid ^= 1;
	else if ((key == 65361 || key == 65363) && ds->bon.is_grid)
		ds->cam.rot_grid[1] += 90 - (180 * (key == 65361));
	else if ((key == 65362 || key == 65364) && ds->bon.is_grid)
		ds->cam.rot_grid[0] += 90 - (180 * (key == 65364));
	else if ((key == 'u' || key == 'j') && !ds->bon.is_grid)
		ds->cam.rotation[0] += 1 - (2 * (key == 'j'));
	else if ((key == 'i' || key == 'k') && !ds->bon.is_grid)
		ds->cam.rotation[1] += 1 - (2 * (key == 'k'));
	else if ((key == 'o' || key == 'l') && !ds->bon.is_grid)
		ds->cam.rotation[2] += 1 - (2 * (key == 'l'));
	else if (key == 's' || key == 'w')
		ds->cam.off_y += 10 - (20 * (key == 'w'));
	else if (key == 'd' || key == 'a')
		ds->cam.off_x += 10 - (20 * (key == 'a'));
	else if (key == '-' || key == '=')
		ds->cam.zoom += 1 - (2 * (key == '-'));
	else if (key == '1' || key == '2')
		ds->cam.height += 1 - (2 * (key == '2'));
	else
		return (check_key2(key, ds));
	return (0);
}

int	fdf(int key, t_mlx *ds)
{
	int	ret;

	if (ds->img)
	{
		mlx_destroy_image(ds->mlx_ptr, ds->img->ptr);
		free(ds->img);
		ds->img = NULL;
	}
	ret = check_key(key, ds);
	if (ret > 0)
		return (0);
	else if (ret < 0)
	{
		free_ds(ds);
		exit(0);
	}
	ds->cam.zoom = ft_max(ds->cam.zoom, 0);
	fdf_draw(ds);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	ds;

	if (argc != 2)
		return (perror("Invalid argument(s).\nUsage : ./fdf [.fdf file]\n"), 1);
	init_mlx(&ds, argv[1]);
	return (0);
}
