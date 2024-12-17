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
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0 - x, points.y0++, 0xffffff);
		if (D <= 0)
		{
			x++;
			D += (2 * dy);
		}
		D -= (2 * dx);
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
			D -= (2 * dy);
		}
		D += (2 * dx);
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
	if ((ret2 >= 0) && (fabs(ret2) > fabs(ret)))
		draw_line_high_asc(p, ds);
	else if (ret2 >= 0)
		draw_line_low_asc(p, ds);
	else if (fabs(ret2) <= fabs(ret))
		draw_line_low_desc(p, ds);
	else
		draw_line_high_desc(p, ds);
}

void	draw_array(t_mlx_data *ds)
{

}

int	check_esc(int key_pressed, t_mlx_data *ds)
{
	printf("KEY = %d\n", key_pressed);
	if (key_pressed == 65307)
	{
		mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
		ds->win_ptr = NULL;
	}
	else if (key_pressed == 97)
		draw_array(ds);
	return (0);
}

void	parse_values(t_mlx_data *ds, char *filename)
{
	int		fd;
	int		len;
	char	*joined_str;
	char	*line;

	fd = open("test.fdf", O_RDONLY);
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
	joined_str[len] = 0;
	ds->array = ft_split(ft_str_replace_char(joined_str, '\n', ' '), ' ');
	ds->array_j = len;
	ds->array_i = array_len(ds->array) / ds->array_j;
}

int main(int argc, char **argv)
{
	t_mlx_data	ds;

	parse_values(&ds, argv[1]);
	ds.mlx_ptr = mlx_init();
	ds.win_ptr = mlx_new_window(ds.mlx_ptr, 1920, 1080, "aaa");
	mlx_loop_hook(ds.mlx_ptr, &test, &ds);
	mlx_hook(ds.win_ptr, KeyPress, KeyPressMask, &check_esc, &ds);
	mlx_loop(ds.mlx_ptr);
	mlx_destroy_display(ds.mlx_ptr);
	free(ds.mlx_ptr);
}
