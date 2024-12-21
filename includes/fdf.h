/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:30:07 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/21 01:48:57 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

typedef struct s_array_info
{
	char	**array;
	char	*done;
	int		array_i;
	int		array_j;
}	t_array_info;

typedef struct s_cam_control
{
	int	x_offset;
	int	y_offset;
	int	cam_zoom;
	int	height;
	int	x_rotation;
	int	y_rotation;
	int	z_rotation;
}	t_cam_control;

typedef struct s_img
{
	void	*mlx_img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*img_ptr;
	t_array_info	array;
	t_cam_control	cam;
}	t_mlx_data;

typedef struct s_line_points
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	angle;
	int	color;
}	t_line_points;

char			*get_next_line(int fd);

/*  Utils  */
void			swap_points(t_line_points *p);
double			get_line_x_coor(int dist, int angle);
double			get_line_y_coor(int dist, int angle);

/*  Init  */
int				close_mlx(t_mlx_data *ds);
void			init_ds(t_mlx_data *ds);
void			init_img(t_mlx_data *ds, int width, int height);
t_line_points	init_p(int angle, t_cam_control cam, t_mlx_data *ds);
t_line_points	prepare_points(int x0, int y0, int x1, int y1);

/*  Draw Stuff  */
char			draw_array(t_mlx_data *ds, int x, int y, t_line_points p);
void			draw_line_init(t_line_points p, t_mlx_data *ds);
char			draw_grid(t_mlx_data *ds, int x, int y, t_line_points p);

/*  Hooks  */
int				loop_wahoo(t_mlx_data *ds);
int				check_key(int key_pressed, t_mlx_data *ds);
char			invalid_key(int key_pressed, t_mlx_data *ds);


#endif
