all :
	$(MAKE) -C mlx/
	$(MAKE) -C libft/
	gcc main.c -I mlx mlx/libmlx_Linux.a libft/libft.a -lXext -lX11 -lm -g
