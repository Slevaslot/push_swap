# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:46:35 by slevaslo          #+#    #+#              #
#    Updated: 2023/03/06 16:03:18 by slevaslo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              =    gcc
RM              =    rm -f

NAME            =    libftprintfgnl.a

LIBRARIES		=	ft_printf/libftprintf.a\
					get_next_line/libget_next_line.a\
					libft/libft.a

all:            $(NAME)

$(NAME):
				make -C libft
				make -C ft_printf
				make -C get_next_line
				ar rcsT $(NAME) $(LIBRARIES)

clean:
				make -C libft clean
				make -C ft_printf clean
				make -C get_next_line clean


fclean:         clean
				make -C libft fclean
				make -C ft_printf fclean
				make -C get_next_line fclean
				$(RM) $(NAME)


re:             fclean $(NAME)

bonus:			re
.PHONY:			all clean fclean re bonus
