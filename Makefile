SRCS			=	main.c\
					tools.c\
					make_stack.c\
					operations_f.c\
					operations_s.c\
					operations_t.c\
					sort_median.c\
					sort_stack.c\
					stack_init.c\

OBJS			=	$(SRCS:.c=.o)

SRCS_BONUS		=	checker.c\
					tools.c\
					make_stack.c\
					operations_f_bonus.c\
					operations_s_bonus.c\
					operations_t_bonus.c\
					sort_stack.c\
					stack_init.c\

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	push_swap
NAME_BONUS		=	checker

LIBRARIES		=	-L libftprintfgnl -lftprintfgnl
INCLUDES		=	-Ilibftprintfgnl

all:			$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(INCLUDES) -g3 -I/usr/include -O3 -c $< -o $@

$(NAME):		$(OBJS)
				make -C libftprintfgnl
				$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) $(LIBRARIES)

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
				make -C libftprintfgnl
				$(CC) $(CFLAGS) $(OBJS_BONUS)  -o $(NAME_BONUS) $(LIBRARIES)

norme:
				norminette $(SRCS) $(SRCS_BONUS) push_swap.h libftprintfgnl

clean:
				make -C libftprintfgnl clean
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				make -C libftprintfgnl fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus norme
