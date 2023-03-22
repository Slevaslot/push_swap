SRCS			=	main.c\
					tools.c\
					make_stack.c\
					operations_first.c\
					operations_second.c\
					operations_third.c\
					operations_fourth.c\
					sort_median.c\
					sort_stack.c\
					stack_init.c\

OBJS			=	$(SRCS:.c=.o)

SRCS_BONUS		=	checker.c\
					tools.c\
					make_stack.c\
					operations_first.c\
					operations_second.c\
					operations_third.c\
					operations_fourth.c\
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

$(NAME):		$(OBJS)
				@echo "\nLa compilation est en cours...\n"
				@make -s -C libftprintfgnl
				@$(CC) $(CFLAGS) -s $(OBJS) -o $(NAME) $(LIBRARIES)
				@echo "La compilation est terminée !\n"

%.o: %.c
				@$(CC) $(CFLAGS) $(INCLUDES) -g3 -I/usr/include -O3 -c $< -o $@ -s

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
				@echo "\nLa compilation est en cours...\n"
				@make -s -C libftprintfgnl
				@$(CC) $(CFLAGS) -s $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBRARIES)
				@echo "La compilation est terminée !\n"

clean:
				@make -s -C libftprintfgnl clean
				@$(RM) $(OBJS) $(OBJS_BONUS)
				@echo "\nLe programme est clean\n"

fclean:			clean
				@make -s -C libftprintfgnl fclean
				@$(RM) $(NAME) $(NAME_BONUS)
				@echo "\net fclean\n"

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus norme
