SRCS := srcs/main.c srcs/draw.c

FLAGS = -Wall -Wextra -Werror

FRAEMWORKS=-framework OpenGL -framework AppKit

NAME	= FdF

HEADER	= -I includes

GCC = gcc

FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(MAKE) -C minilibx_macos/ all
	cp minilibx_macos/libmlx.a .
	$(GCC) -g $(FLAGS) -o FdF libft.a libmlx.a $(SRCS) $(FRAEMWORKS) $(HEADER)

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