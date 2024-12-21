/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:55:11 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/21 01:53:17 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_wahoo(t_mlx_data *ds)
{
	(void)ds;
	return (0);
}

int	check_key(int key_pressed, t_mlx_data *ds)
{
	static int	angle = 25;

	if (key_pressed == 65307)
		return (close_mlx(ds));
	else if (key_pressed == '`')
		angle *= -1;
	else if (key_pressed == 65362 && angle > 0)
		angle--;
	else if (key_pressed == 65364 && angle > 0)
		angle++;
	else if (invalid_key(key_pressed, ds))
		return (0);
	ds->array.done = ft_calloc(sizeof(char), ds->array.array_i
			* ds->array.array_j);
	if (angle == 0)
		angle += 360;
	if (ds->img_ptr)
		mlx_destroy_image(ds->mlx_ptr, (void *)ds->img_ptr);
	ds->img_ptr = mlx_new_image(ds->mlx_ptr, 1920, 1080);
	draw_array(ds, 0, 0, init_p(angle, ds->cam, ds));
	mlx_put_image_to_window(ds->mlx_ptr, ds->win_ptr, ds->img_ptr, 0, 0);
	free(ds->array.done);
	return (0);
}

char	invalid_key(int key_pressed, t_mlx_data *ds)
{
	if (key_pressed == 'p')
		ds->cam.cam_zoom *= -1;
	else if (key_pressed == 'a' || key_pressed == 'd')
		ds->cam.x_offset += 30 * (1 - ((key_pressed == 'a') * 2));
	else if (key_pressed == 'w' || key_pressed == 's')
		ds->cam.y_offset -= 30 * (1 - ((key_pressed == 's') * 2));
	else if (key_pressed == 'u')
		ds->cam.x_rotation++;
	else if (key_pressed == 'j')
		ds->cam.x_rotation--;
	else if (key_pressed == 'i')
		ds->cam.y_rotation++;
	else if (key_pressed == 'k')
		ds->cam.y_rotation--;
	else if (key_pressed == 'o' || key_pressed == 'l')
		ds->cam.z_rotation += (1 - ((key_pressed == 'o') * 2));
	else if (key_pressed == '1' || key_pressed == '2')
		ds->cam.height += 1 - ((key_pressed == '1') * 2);
	else if (key_pressed == 65451)
		ds->cam.cam_zoom++;
	else if (key_pressed == '-')
		ds->cam.cam_zoom--;
	else
		return (1);
	return (0);
}
