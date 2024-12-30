# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 02:58:46 by gakarbou          #+#    #+#              #
#    Updated: 2024/12/30 00:54:28 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRCS_DIR = srcs/
HEAD_DIR = includes/
LIBFT_DIR = libft/
MLX_DIR = mlx/
OBJS_DIR = objs/

MLX_FLAGS = -lX11 -lXext -lm
FDF_LIBS = libft/libft.a mlx/libmlx_Linux.a

SRCS = main.c \
	   init.c \
	   utils.c \
	   rotation.c \
	   draw_array.c

FILES = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(SRCS:.c=.o)
OBJS_FILES = $(addprefix $(OBJS_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	$(CC) $(OBJS_FILES) -I $(LIBFT_DIR)$(HEAD_DIR) -I $(MLX_DIR) -I $(HEAD_DIR) $(FDF_LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) -I $(LIBFT_DIR)$(HEAD_DIR) -I $(MLX_DIR) -I $(HEAD_DIR) -c $< -o $@ -g

clean :
	rm -f $(OBJS_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
