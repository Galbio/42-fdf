# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 21:48:01 by gakarbou          #+#    #+#              #
#    Updated: 2024/12/21 01:39:14 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEAD_DIR = includes/
SRCS_DIR = srcs/
LIBFT_DIR = libft/
MLX_DIR = mlx/

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L./mlx -lmlx -lX11 -lXext -lm

LIBFT = libft.a
MLX = libmlx_Linux.a

SRCS = main.c \
	   init.c \
	   utils.c \
	   hooks.c \
	   draw_line.c \
	   draw_array.c

FILES = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(FILES:.c=.o)

all : $(NAME)
bonus : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "Done compiling libft!"
	@echo ""
	@echo "Compiling mlx..."
	@make -C mlx/ > /dev/null
	@echo "Done compiling mlx!"
	@echo ""
	$(CC) $(OBJS) $(FLAGS) -I $(HEAD_DIR) -I $(MLX_DIR) $(MLX_DIR)$(MLX) $(LIBFT_DIR)$(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR)

clean :
	rm -f $(OBJS)

fclean : clean
	@echo "\033[0;31mRemoving libft.a and libft object..."
	@make $@ -C $(LIBFT_DIR) > /dev/null
	@echo "Finished removing libft.a and all objects!"
	@echo ""
	@echo "Removing libmlx and objects..."
	@make clean -C $(MLX_DIR) > /dev/null
	@echo "Finished removing libmlx and objects!\033[0m"
	rm -f $(NAME)

re : fclean all
