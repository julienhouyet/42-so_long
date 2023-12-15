# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 10:09:58 by jhouyet           #+#    #+#              #
#    Updated: 2023/12/15 14:12:30 by jhouyet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC			= 	so_long.c \
				exit.c \
				maps_checker.c \
				maps_valid.c \
				game.c \
				utils.c \
				hooks.c \
				moves.c \
				maps_path.c

OBJ			= ${SRC:.c=.o}

LIBFT		= libft.a

LIBFT_PATH	= libft

MLX			= libmlx.a

MLX_PATH	= mlx

CC			= gcc

RM			= rm -f

C_FLAGS	= -Wall -Wextra -Werror

MLX_FLAGS = -framework OpenGL -framework AppKit 

all: ${NAME}

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

${NAME}: ${OBJ} ${LIBFT} ${MLX}
	${CC} ${C_FLAGS} ${MLX_FLAGS} ${OBJ} -o ${NAME} ${LIBFT} ${MLX}

${LIBFT}:
	${MAKE} -C ${LIBFT_PATH}
	mv ${LIBFT_PATH}/${LIBFT} .

${MLX}:
	${MAKE} -C ${MLX_PATH}
	mv ${MLX_PATH}/${MLX} .

clean:
	${MAKE} clean -C ${LIBFT_PATH}
	${MAKE} clean -C ${MLX_PATH}
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME} ${LIBFT} ${MLX}

re:	fclean all

.PHONY:	all clean fclean re