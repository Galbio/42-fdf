/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:06:03 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/20 20:08:33 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_col
{
	int	red;
	int	green;
	int	blue;
}	t_col;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	t_col	color;
}	t_point;

typedef struct s_line
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	t_col	colors[2];
	double	cur_color;
	double	avg_color;
}	t_line;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_array
{
	int			i;
	int			j;
	char		**array;
	char		*done;
	int			*height;
	t_col		*colors;
	int			extr[2];
	t_point		**map;
}	t_array;

typedef struct s_cam
{
	int		off_y;
	int		off_x;
	int		rotation[3];
	int		rot_grid[3];
	double	height;
	double	zoom;
}	t_cam;

typedef struct s_bonus
{
	char	is_grid;
	char	draw_lines;
	char	colors;
	int		mouse_info[3];
}	t_bonus;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	must_draw;
	t_img	*img;
	t_cam	cam;
	t_array	array;
	t_bonus	bon;
}	t_mlx;

void	change_x(t_mlx *ds, int rotation[3]);

void	putpx(t_mlx *ds, t_line p);
double	fcos(int angle);
double	fsin(int angle);
void	swap_points(t_line *p);
void	free_array(t_mlx *ds);

void	draw_line_init(t_mlx *ds, t_line p);
void	draw_line(t_mlx *ds, t_line p, char incr_x, char incr_y);
void	draw_array(t_mlx *ds, int j);

void	init_mlx(t_mlx *ds, char *filename);
void	init_points(t_mlx *ds);
void	*init_img(void *mlx_ptr);
void	parse_map(char *filename, t_mlx *ds);
void	fill_map(t_mlx *ds);

int		aled(t_mlx *ds);
void	fdf_draw(t_mlx *ds);
int		fdf(int key, t_mlx *ds);
void	free_ds(t_mlx *ds);

int		check_mouse(int button, int x, int y, t_mlx *ds);
int		mouse_stop(int button, int x, int y, t_mlx *ds);
int		close_fdf(t_mlx *ds);

void	init_height(t_mlx *ds);
t_col	nb_to_rgb(int color);
void	fill_colors(t_mlx *ds);

#endif
