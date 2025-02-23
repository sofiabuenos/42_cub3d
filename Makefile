# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 11:37:28 by shrodrig          #+#    #+#              #
#    Updated: 2025/02/10 17:29:59 by shrodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .

LIBFT_PATH = lib/libft
LIBFT = -L ${LIBFT_PATH} -lft
MLX_PATH = lib/mlx
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm 

SRC = main.c

OBJS = ${SRC:.c=.o}

%.o : %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C ${LIBFT_PATH}
		make -C ${MLX_PATH}
		${CC} ${OBJS} ${LIBFT} ${MLX} ${CFLAGS} -o ${NAME}

all: ${NAME}

clean:
		make -C ${LIBFT_PATH} clean
		make -C ${MLX_PATH} clean
		${RM} ${OBJS}

fclean: clean
		make -C ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
