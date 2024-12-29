/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:04:34 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/29 22:41:20 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_points(t_line *p)
{
	double	temp;

	temp = p->x0;
	p->x0 = p->x1;
	p->x1 = temp;
	temp = p->y0;
	p->y0 = p->y1;
	p->y1 = temp;
}

int	aled(t_mlx *ds)
{
	(void)ds;
	return (0);
}

void	putpx(t_mlx *ds, float x, float y, int color)
{
	char	*pixel;
	int		int_x;
	int		int_y;

	y += ds->cam.off_y;
	x += ds->cam.off_x;
	if (x < 0 || y < 0)
		return ;
	else if (x >= 1000 || y >= 1000)
		return ;
	int_x = (int)x;
	int_y = (int)y;
	pixel = ds->img->addr + (int_y * ds->img->size_line
			+ int_x * (ds->img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	draw_line(t_mlx *ds, t_line p, char incr_x, char incr_y)
{
	double	dx;
	double	dy;
	double	error;
	double	error2;

	dx = ft_abs(p.x0 - p.x1);
	dy = ft_abs(p.y0 - p.y1) * -1;
	error = dx + dy;
	while (1)
	{
		putpx(ds, p.x0, p.y0, 0xFFFFFF);
		if ((p.x0 == p.x1) && (p.y0 == p.y1))
			break ;
		error2 = error * 2;
		if (error2 >= dy)
		{
			error += dy;
			p.x0 += incr_x;
		}
		if (error2 <= dx)
		{
			error += dx;
			p.y0 += incr_y;
		}
	}
}

void	draw_line_init(t_mlx *ds, t_line p)
{
	char	incr_x;
	char	incr_y;

	incr_x = 1;
	if (p.x1 < p.x0)
		incr_x = -1;
	incr_y = -1;
	if (p.y1 > p.y0)
		incr_y = 1;
	draw_line(ds, p, incr_x, incr_y);
}

void	draw_array(t_mlx *ds, int x, int y)
{
	t_line	p;

	if (ds->array.done[(y * ds->array.i) + x])
		return ;
	ds->array.done[(y * ds->array.i) + x] = 1;
	p.x0 = ds->array.map[y][x].x;
	p.y0 = ds->array.map[y][x].y;
	if (x < (ds->array.i - 1))
	{
		p.x1 = ds->array.map[y][x + 1].x;
		p.y1 = ds->array.map[y][x + 1].y;
		draw_line_init(ds, p);
		draw_array(ds, x + 1, y);
	}
	if (y < (ds->array.j - 1))
	{
		p.x1 = ds->array.map[y + 1][x].x;
		p.y1 = ds->array.map[y + 1][x].y;
		draw_line_init(ds, p);
		draw_array(ds, x, y + 1);
	}
}

double	fcos(int angle)
{
	return (cos(angle * (M_PI / 180)));
}

double	fsin(int angle)
{
	return (sin(angle * (M_PI / 180)));
}

void	change_x(t_mlx *ds, int x)
{
	int		i;
	int		j;
	double	temp;
	double	temp2;

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			temp = ds->array.map[j][i].y;
			temp2 = ds->array.map[j][i].z;
			ds->array.map[j][i].y = round((temp * fcos(x)) + (-temp2 * fsin(x)));
			ds->array.map[j][i].z = round((temp * fsin(x)) + (temp2 * fcos(x)));
		}
	}
}

void	change_y(t_mlx *ds, int y)
{
	int		i;
	int		j;
	double	temp;
	double	temp2;

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			temp = ds->array.map[j][i].x;
			temp2 = ds->array.map[j][i].z;
			ds->array.map[j][i].x = round((temp * fcos(y)) + (temp2 * fsin(y)));
			ds->array.map[j][i].z = round((-temp * fsin(y)) + (temp2 * fcos(y)));
		}
	}
}

void	change_z(t_mlx *ds, int z)
{
	int		i;
	int		j;
	double	temp;
	double	temp2;

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			temp = ds->array.map[j][i].x;
			temp2 = ds->array.map[j][i].y;
			ds->array.map[j][i].x = round((temp * fcos(z)) + (temp2 * fsin(z) * -1));
			ds->array.map[j][i].y = round((temp * fsin(z)) + (temp2 * fcos(z)));
		}
	}
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

void	free_array(t_mlx *ds)
{
	int	i;

	free(ds->array.done);
	i = -1;
	while (++i < ds->array.j)
		free(ds->array.map[i]);
	free(ds->array.map);
}

int	test(int key, t_mlx *ds)
{
	if (ds->img)
	{
		mlx_destroy_image(ds->mlx_ptr, ds->img->ptr);
		free(ds->img);
	}
	if (key == 65307)
	{
		mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
		return (0);
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
	{
		ds->cam.zoom += 1 - (2 * (key == '-'));
		ds->cam.height -= 1 - (2 * (key == '-'));
	}
	else if (key == '1' || key == '2')
		ds->cam.height += 1 - (2 * (key == '2'));
	init_points(ds);
	change_x(ds, ds->cam.rotation[0]);
	change_y(ds, ds->cam.rotation[1]);
	change_z(ds, ds->cam.rotation[2]);
	ds->img = init_img(ds->mlx_ptr);
	ds->array.done = ft_calloc(sizeof(char), ds->array.i * ds->array.j);
	draw_array(ds, 0, 0);
	free_array(ds);
	mlx_put_image_to_window(ds->mlx_ptr, ds->win_ptr, ds->img->ptr, 0, 0);
	return (0);
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
	free(joined_str);
}

void	fill_map(t_mlx *ds, int x, int y)
{
	int	i;
	int	j;

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			ds->array.map[j][i].x = (i - (ds->array.i / 2)) * ds->cam.zoom;
			ds->array.map[j][i].y = (j - (ds->array.j / 2)) * ds->cam.zoom;
			ds->array.map[j][i].z = ft_atoi(ds->array.array[(j * ds->array.i) + i]) * (ds->cam.zoom + ds->cam.height);
		}
	}
}

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
	fill_map(ds, 0, 0);
}

void	init_mlx(t_mlx *ds, char *file)
{
	parse_map(file, ds);
	ds->mlx_ptr = mlx_init();
	ds->win_ptr = mlx_new_window(ds->mlx_ptr, 1000, 1000, "SdF");
	ds->img = NULL;
	ds->cam.rotation[0] = 45;
	ds->cam.rotation[1] = -36;
	ds->cam.rotation[2] = 30;
	ds->cam.off_x = 500;
	ds->cam.off_y = 400;
	ds->cam.zoom = 30;
	ds->cam.height = 0;
	mlx_hook(ds->win_ptr, 2, 1L << 0, &test, ds);
	mlx_loop_hook(ds->mlx_ptr, &aled, ds);
	mlx_loop(ds->mlx_ptr);
	mlx_destroy_display(ds->mlx_ptr);
	free(ds->mlx_ptr);
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
