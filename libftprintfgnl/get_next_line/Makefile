# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 11:25:53 by slevaslo          #+#    #+#              #
#    Updated: 2023/03/27 14:41:30 by slevaslo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	get_next_line.c\
		get_next_line_utils.c\

OBJS = ${SRCS:.c=.o}

NAME = libget_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

.c.o :
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: $(OBJS)
			ar rcs ${NAME} ${OBJS}
clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${OBJS} ${NAME}

re: fclean all

.PHONY:		all clean fclean re
