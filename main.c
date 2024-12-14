#include <X11/X.h>
#include <X11/keysym.h>
#include "fdf.h"

int	test(t_mlx_data *ds)
{
	static int	frame_rule = 0;
	int	mpx;
	int	mpy;

	if (!ds->win_ptr)
		return (1);
	mlx_mouse_get_pos(ds->mlx_ptr, ds->win_ptr, &mpx, &mpy);
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, mpx, mpy, 0xffffff);
	frame_rule++;
	if (frame_rule == 360)
		frame_rule = 0;
	if (!frame_rule)
	{
		printf("X = %d | Y = %d\n", mpx, mpy);
	}
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
	ds.win_ptr = mlx_new_window(ds.mlx_ptr, 512, 512, "aaa");
	mlx_loop_hook(ds.mlx_ptr, &test, &ds);
	mlx_hook(ds.win_ptr, KeyPress, KeyPressMask, &check_esc, &ds);
	mlx_loop(ds.mlx_ptr);
	mlx_destroy_display(ds.mlx_ptr);
	free(ds.mlx_ptr);
}
