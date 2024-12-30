/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:06:03 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/30 01:05:36 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_line
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
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
	int		i;
	int		j;
	char	**array;
	char	*done;
	t_point	**map;
}	t_array;

typedef struct s_cam
{
	int		off_y;
	int		off_x;
	int		rotation[3];
	int		height;
	int		zoom;
}	t_cam;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_cam	cam;
	t_array	array;
}	t_mlx;

void	change_x(t_mlx *ds, int x);
void	change_y(t_mlx *ds, int y);
void	change_z(t_mlx *ds, int z);

void	putpx(t_mlx *ds, float x, float y, int color);
double	fcos(int angle);
double	fsin(int angle);
void	swap_points(t_line *p);
void	free_array(t_mlx *ds);

void	draw_line_init(t_mlx *ds, t_line p);
void	draw_line(t_mlx *ds, t_line p, char incr_x, char incr_y);
void	draw_array(t_mlx *ds, int x, int y);

void	init_mlx(t_mlx *ds, char *filename);
void	init_points(t_mlx *ds);
void	*init_img(void *mlx_ptr);
void	parse_map(char *filename, t_mlx *ds);
void	fill_map(t_mlx *ds, int x, int y);

int		aled(t_mlx *ds);
void	fdf_draw(t_mlx *ds);
int		fdf(int key, t_mlx *ds);

#endif
