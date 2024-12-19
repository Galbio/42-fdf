all :
	$(MAKE) -C mlx/
	$(MAKE) -C libft/
	gcc -Wall -Wextra main.c -I mlx mlx/libmlx_Linux.a libft/libft.a -lXext -lX11 -lm -g
