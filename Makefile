all :
	$(MAKE) -C mlx/
	gcc main.c -I mlx/ mlx/libmlx.a
