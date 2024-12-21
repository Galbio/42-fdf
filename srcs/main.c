/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:06:01 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/21 01:53:51 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		free(line);
	}
	ds->array.array = ft_split(ft_str_replace_char(joined_str, '\n', ' '), ' ');
	ds->array.array_j = len;
	ds->array.array_i = array_len(ds->array.array) / ds->array.array_j;
	free(joined_str);
}

void	setup_mlx(t_mlx_data *ds)
{
	ds->mlx_ptr = mlx_init();
	ds->win_ptr = mlx_new_window(ds->mlx_ptr, 1920, 1080, "Fil de Fer");
	init_ds(ds);
	ds->array.done = ft_calloc(sizeof(char), ds->array.array_i
			* ds->array.array_j);
	if (!ds->array.done)
		return ;
	draw_array(ds, 0, 0, init_p(25, ds->cam, ds));
	free(ds->array.done);
	mlx_loop_hook(ds->mlx_ptr, &loop_wahoo, ds);
	mlx_hook(ds->win_ptr, 2, KeyPressMask, &check_key, ds);
	mlx_hook(ds->win_ptr, 17, 0, &close_mlx, ds);
	mlx_loop(ds->mlx_ptr);
	if (ds->win_ptr)
	{
		mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
		free(ds->win_ptr);
	}
	mlx_destroy_display(ds->mlx_ptr);
	free(ds->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx_data	ds;
	int			i;

	if (argc != 2)
		return (1);
	parse_values(&ds, argv[1]);
	setup_mlx(&ds);
	i = -1;
	while (ds.array.array[++i])
		free(ds.array.array[i]);
	return (free(ds.array.array), 0);
}
