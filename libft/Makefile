# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:12:41 by gakarbou          #+#    #+#              #
#    Updated: 2025/01/02 15:06:33 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft/
FT_PRINTF_DIR = ft_printf/
GNL_DIR = gnl/
HEAD_DIR = includes/

NAME = libft.a

LIBFT_SRCS = ft_strlen.c \
		ft_bzero.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_atoi_base.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_maths.c \
		ft_iscmd.c \
		ft_memcmd.c \
		ft_write_fd.c \

LIBFT_BONUS_SRCS = ft_lstiter_bonus.c \
			 ft_lstmap_bonus.c \
			 ft_lstadd.c \
			 ft_lstinfo.c \
			 ft_lstclear.c \
			 ft_lstmaths.c

GNL_SRCS = get_next_line.c \
				 get_next_line_utils.c

FT_PRINTF_SRCS = flags.c \
				 writers.c \
				 writers2.c \
				 ft_printf.c \
				 utils.c


LIBFT_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS))
LIBFT_BONUS_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_BONUS_SRCS))

GNL_FILES = $(addprefix $(GNL_DIR), $(GNL_SRCS))

FT_PRINTF_FILES = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_SRCS))

LIBFT_OBJS = $(LIBFT_FILES:.c=.o)
LIBFT_OBJS_BONUS = $(LIBFT_BONUS_FILES:.c=.o)

GNL_OBJS = $(GNL_FILES:.c=.o)

FT_PRINTF_OBJS = $(FT_PRINTF_FILES:.c=.o)


all : $(NAME)

$(NAME) : $(LIBFT_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	ar -rcs $(NAME) $(LIBFT_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

bonus : $(LIBFT_OBJS) $(LIBFT_OBJS_BONUS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	ar -rcs $(NAME) $(LIBFT_OBJS) $(LIBFT_OBJS_BONUS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

debug : FLAGS = $(DEBUG_FLAGS)
debug : bonus

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR)

clean :
	rm -f $(LIBFT_OBJS) $(LIBFT_OBJS_BONUS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
