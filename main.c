#include <X11/X.h>
#include <X11/keysym.h>
#include "fdf.h"

int	test(t_mlx_data *ds)
{
	static int i = 0;
	
	if (ds->win_ptr && !i)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, 100, 100, 0xffffff);
	}
	i++;
	return (0);
}

int	check_esc(int key_pressed, t_mlx_data *ds)
{
	if (key_pressed == XK_Escape)
	{
		mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
		ds->win_ptr = NULL;
	}
	return (0);
}

int main(void)
{
	t_mlx_data	ds;

	ds.mlx_ptr = mlx_init();
	ds.win_ptr = mlx_new_window(ds.mlx_ptr, 256, 256, "aaa");
	mlx_loop_hook(ds.mlx_ptr, &test, &ds);
	mlx_hook(ds.win_ptr, KeyPress, KeyPressMask, &check_esc, &ds);
	mlx_loop(ds.mlx_ptr);
	free(ds.mlx_ptr);
}
