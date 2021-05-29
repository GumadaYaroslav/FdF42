SRCS := srcs/main.c

FLAGS = -Wall -Wextra -Werror

# INC = ../includes/push_swap.h
#LIBFT	= ./libft/libft.a

NAME	= FdF

HEADER	= -I includes

GCC = gcc

FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(GCC) -g $(FLAGS) -o FdF libft.a $(SRCS) $(HEADER)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf libft.a
	rm -rf checker
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re