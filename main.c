#include <X11/X.h>
#include <X11/keysym.h>
#include "fdf.h"

int	test(t_mlx_data *ds)
{
	return (0);
}

t_line_points	prepare_points(int x0, int y0, int x1, int y1)
{
	t_line_points	dest;

	dest.x0 = x0;
	dest.x1 = x1;
	dest.y0 = y0;
	dest.y1 = y1;
	return (dest);
}

void	draw_line_high_desc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	x;
	int	D;

	dx = points.x1 - points.x0;
	dy = points.y0 - points.y1;
	D = (2 * dx) - dy;
	x = 0;
	while (points.y0 != points.y1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0 + x, points.y0++, 0xffffff);
		if (D >= 0)
		{
			x++;
			D -= fabs(2 * dy);
		}
		D += fabs(2 * dx);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	draw_line_high_asc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	x;
	int	D;

	dx = points.x1 - points.x0;
	dy = points.y0 - points.y1;
	D = (2 * dx) - dy;
	x = 0;
	while (points.y0 != points.y1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0 + x, points.y0--, 0xffffff);
		if (D >= 0)
		{
			x++;
			D -= fabs(2 * dy);
		}
		D += fabs(2 * dx);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	draw_line_low_desc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	y;
	int	D;

	dx = points.x1 - points.x0;
	dy = points.y1 - points.y0;
	D = (2 * dy) - dx;
	y = 0;
	while (points.x0 != points.x1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0++, points.y0 + y, 0xffffff);
		if (D >= 0)
		{
			y++;
			D -= (2 * dx);
		}
		D += (2 * dy);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	draw_line_low_asc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	y;
	int	D;

	dx = points.x1 - points.x0;
	dy = points.y0 - points.y1;
	D = (2 * dy) - dx;
	y = 0;
	while (points.x0 != points.x1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0++, points.y0 - y, 0xffffff);
		if (D >= 0)
		{
			y++;
			D -= (2 * dx);
		}
		D += (2 * dy);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	swap_points(t_line_points *p)
{
	int	temp;

	temp = p->x0;
	p->x0 = p->x1;
	p->x1 = temp;
	temp = p->y0;
	p->y0 = p->y1;
	p->y1 = temp;
}

void	draw_line_init(t_line_points p, t_mlx_data *ds)
{
	int	ret;
	int	ret2;

	ret = p.x0 - p.x1;
	if (ret > 0)
		swap_points(&p);
	ret2 = p.y0 - p.y1;
	if ((fabs(p.y0 - p.y1) > fabs(p.x0 - p.x1)) && (ret2 >= 0))
		draw_line_high_asc(p, ds);
	else if (ret2 >= 0)
		draw_line_low_asc(p, ds);
	else if (fabs(p.y0 - p.y1) > fabs(p.x0 - p.x1))
		draw_line_high_desc(p, ds);
	else
		draw_line_low_desc(p, ds);
}

t_line_points	init_p(int angle, t_cam_control cam)
{
	t_line_points	dest;

	dest.x0 = 650 + cam.x_offset;
	dest.y0 = 650 + cam.y_offset;
	dest.angle = angle;
	return (dest);
}

double	get_line_x_coor(int dist, int angle)
{
	return (dist * cos(angle * (M_PI / 180)));
}

double	get_line_y_coor(int dist, int angle)
{
	return (dist * sin(angle * (M_PI / 180)));
}

void	draw_array(t_mlx_data *ds, int x, int y, t_line_points p)
{
	t_line_points	save;
	int				up_factor;
	int				up_factor_other;

	if (ds->array.done[(y * ds->array.array_i) + x])
		return ;
	ds->array.done[(y * ds->array.array_i) + x] = 1;
	save = p;
	up_factor = ft_atoi(ds->array.array[(ds->array.array_i * y) + x]) * (ds->cam.cam_zoom);
	p.y1 = p.y0 + get_line_y_coor(ds->cam.cam_zoom, p.angle);
	if (x < (ds->array.array_i - 1))
	{
		p.x1 = p.x0 + get_line_x_coor(ds->cam.cam_zoom, p.angle);
		up_factor_other = ft_atoi(ds->array.array[(ds->array.array_i * y) + x + 1]) * (ds->cam.cam_zoom);
		p.y0 -= up_factor;
		p.y1 -= up_factor_other;
		draw_line_init(p, ds);
		p.y1 += up_factor_other;
		p.y0 += up_factor;
		swap_points(&p);
		draw_array(ds, x + 1, y, p);
		p = save;
	}
	p.y1 = p.y0 + get_line_y_coor(ds->cam.cam_zoom, (p.angle + 90));
	if (y < (ds->array.array_j - 1))
	{
		p.x1 = p.x0 + get_line_x_coor(ds->cam.cam_zoom, (p.angle + 90));
		up_factor_other = ft_atoi(ds->array.array[(ds->array.array_i * (y + 1)) + x]) * (ds->cam.cam_zoom);
		p.y0 -= up_factor;
		p.y1 -= up_factor_other;
		draw_line_init(p, ds);
		p.y1 += up_factor_other;
		p.y0 += up_factor;
		swap_points(&p);
		draw_array(ds, x, y + 1, p);
		p = save;
	}
}

void	draw_line(t_mlx_data *ds, int x, int y, t_line_points p)
{
	t_line_points	save;

	save = p;
	p.x1 = p.x0 + get_line_x_coor(ds->cam.cam_zoom, p.angle);
	p.y1 = p.y0 + get_line_y_coor(ds->cam.cam_zoom, p.angle);
	draw_line_init(p, ds);
	p.x1 = p.x0 + get_line_x_coor(ds->cam.cam_zoom, (p.angle + 90));
	p.y1 = p.y0 + get_line_y_coor(ds->cam.cam_zoom, (p.angle + 90));
	draw_line_init(p, ds);
}

int	check_key(int key_pressed, t_mlx_data *ds)
{
	static int	angle = 90;

	printf("KEY = %d\n", key_pressed);
	if (key_pressed == 65307)
	{
		mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
		if (ds->img_ptr)
			mlx_destroy_image(ds->mlx_ptr, ds->img_ptr);
		ds->win_ptr = NULL;
		return (0);
	}
	else if (key_pressed == 'a')
		ds->cam.x_offset -= 30;
	else if (key_pressed == 'd')
		ds->cam.x_offset += 30;
	else if (key_pressed == 'w')
		ds->cam.y_offset -= 30;
	else if (key_pressed == 's')
		ds->cam.y_offset += 30;
	else if (key_pressed == 65362)
		angle--;
	else if (key_pressed == 65364)
		angle++;
	else if (key_pressed == 65451)
		ds->cam.cam_zoom++;
	else if (key_pressed == '-')
		ds->cam.cam_zoom--;
	else if (key_pressed == 'u')
		ds->cam.x_rotation += 1;
	else if (key_pressed == 'j')
		ds->cam.x_rotation -= 1;
	else
		return (0);
	ds->array.done = ft_calloc(sizeof(char), ds->array.array_i * ds->array.array_j);
	printf("ANGLE = %d\n", angle);
	if (ds->img_ptr)
		mlx_destroy_image(ds->mlx_ptr, ds->img_ptr);
	ds->img_ptr = mlx_new_image(ds->mlx_ptr, 1920, 1080);
	mlx_put_image_to_window(ds->mlx_ptr, ds->win_ptr, ds->img_ptr, 0, 0);
	draw_array(ds, 0, 0, init_p(ds->cam.x_rotation, ds->cam));
	//draw_line(ds, 0, 0, init_p(ds->cam.x_rotation, ds->cam));
	free(ds->array.done);
	return (0);
}

int	check_mouse(int mouse_button, t_mlx_data *ds)
{
	printf("mouse = %d\n", mouse_button);
	if (mouse_button == 4)
		ds->cam.cam_zoom += 1;
	else if (mouse_button == 6)
		ds->cam.cam_zoom -= 1;
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	parse_values(t_mlx_data *ds, char *filename)
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
	}
	ds->array.array = ft_split(ft_str_replace_char(joined_str, '\n', ' '), ' ');
	ds->array.array_j = len;
	ds->array.array_i = array_len(ds->array.array) / ds->array.array_j;
}

void	init_ds(t_mlx_data *ds)
{
	ds->cam.x_offset = 0;
	ds->cam.y_offset = 0;
	ds->cam.cam_zoom = 30;
	ds->cam.x_rotation = 47;
}

int main(int argc, char **argv)
{
	t_mlx_data	ds;
	int			i;

	parse_values(&ds, argv[1]);
	ds.mlx_ptr = mlx_init();
	ds.win_ptr = mlx_new_window(ds.mlx_ptr, 1020, 1020, "aaa");
	ds.img_ptr = NULL;
	init_ds(&ds);
	mlx_loop_hook(ds.mlx_ptr, &test, &ds);
	mlx_hook(ds.win_ptr, 2, KeyPressMask, &check_key, &ds);
	//mlx_hook(ds.win_ptr, 4, ButtonPressMask, &check_mouse, &ds);
	mlx_loop(ds.mlx_ptr);
	mlx_destroy_display(ds.mlx_ptr);
	free(ds.mlx_ptr);
	i = -1;
	while (++i < ds.array.array_j)
		free(ds.array.array[i]);
	free(ds.array.array);
}
