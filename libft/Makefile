# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 09:14:53 by jhouyet           #+#    #+#              #
#    Updated: 2023/12/12 10:05:57 by jhouyet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_atoi.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_putendl_fd.c	\
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_printf/ft_printf.c \
				ft_printf/ft_printf_count.c \
				ft_printf/ft_printf_char.c \
				ft_printf/ft_printf_str.c \
				ft_printf/ft_printf_pointer.c \
				ft_printf/ft_printf_number.c \
				ft_printf/ft_printf_unsigned_number.c \
				ft_printf/ft_printf_hexa.c \
				ft_printf/ft_puthexa_fd.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

HEADERS		= libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c ${HEADERS}
			${CC} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${HEADERS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

$(OBJSB): $(SRCSB)

clean:
	${RM} ${OBJSB} ${OBJS}

fclean: clean
	${RM} $(NAME)

re:	fclean all

.PHONY:	all clean fclean re