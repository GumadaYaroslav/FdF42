SRCS := srcs/main.c srcs/draw.c srcs/events.c srcs/pars.c srcs/utils1.c

O_FILES := main.o draw.o events.o pars.o utils1.o

FLAGS = -Wall -Wextra -Werror

FRAEMWORKS=-framework OpenGL -framework AppKit

NAME	= fdf

HEADERS = includes/fdf.h includes/libft.h

HEADER	= -I includes

GCC = gcc

FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME): srcs/ $(SRCS) $(HEADERS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(MAKE) -C minilibx_macos/ all
	cp minilibx_macos/libmlx.a .
	$(GCC) -c $(FLAGS) $(SRCS)
	$(GCC) $(FLAGS) -o fdf libft.a libmlx.a $(O_FILES) $(FRAEMWORKS) $(HEADER)

bonus: srcs/ $(SRCS) $(HEADERS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(MAKE) -C minilibx_macos/ all
	cp minilibx_macos/libmlx.a .
	$(GCC) -c $(FLAGS) $(SRCS)
	$(GCC) $(FLAGS) -o fdf libft.a libmlx.a $(O_FILES) $(FRAEMWORKS) $(HEADER)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_macos
	rm -rf libft.a
	rm -rf libmlx.a
	rm -rf $(O_FILES)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re