# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 02:58:46 by gakarbou          #+#    #+#              #
#    Updated: 2025/01/16 15:10:12 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
C_FLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
HEAD_DIR = includes/
LIBFT_DIR = libft/
MLX_DIR = minilibx/
OBJS_DIR = objs/

MLX_FLAGS = -lX11 -lXext -lm
FDF_LIBS = libft/libft.a minilibx/libmlx_Linux.a

SRCS = main.c \
	   init.c \
	   utils.c \
	   utils2.c \
	   color.c \
	   rotation.c \
	   mouse_bonus.c \
	   draw_array.c

FILES = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(SRCS:.c=.o)
OBJS_FILES = $(addprefix $(OBJS_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	make -C minilibx/
	make -C libft/
	$(CC) $(C_FLAGS) $(OBJS_FILES) -I $(LIBFT_DIR)$(HEAD_DIR) -I $(MLX_DIR) -I $(HEAD_DIR) $(FDF_LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(C_FLAGS) -I $(LIBFT_DIR)$(HEAD_DIR) -I $(MLX_DIR) -I $(HEAD_DIR) -c $< -o $@ -g

clean :
	rm -f $(OBJS_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
