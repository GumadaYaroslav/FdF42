SRCS := srcs/main.c srcs/draw.c

FLAGS = -Wall -Wextra -Werror

FRAEMWORKS=-framework OpenGL -framework AppKit

NAME	= fdf

HEADER	= -I includes

GCC = gcc

FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(MAKE) -C minilibx_macos/ all
	cp minilibx_macos/libmlx.a .
	$(GCC) -g $(FLAGS) -o fdf libft.a libmlx.a $(SRCS) $(FRAEMWORKS) $(HEADER)

bonus: $(SRCS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(MAKE) -C minilibx_macos/ all
	cp minilibx_macos/libmlx.a .
	$(GCC) -g $(FLAGS) -o fdf libft.a libmlx.a $(SRCS) $(FRAEMWORKS) $(HEADER)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_macos
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./minilibx_macos
	rm -rf libft.a
	rm -rf checker
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re