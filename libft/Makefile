# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmilissa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 10:38:54 by fmilissa          #+#    #+#              #
#    Updated: 2021/04/19 10:38:56 by fmilissa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h
LIST =  ft_bzero.c		ft_calloc.c		ft_isalnum.c\
		ft_isalpha.c	ft_isascii.c	ft_isdigit.c\
		ft_isprint.c	ft_memccpy.c	ft_memchr.c\
		ft_memcmp.c		ft_memmove.c	ft_memset.c\
		ft_strchr.c		ft_strdup.c 	ft_strlcat.c\
		ft_strlcpy.c    ft_strlen.c     ft_strncmp.c\
		ft_strnstr.c	ft_strrchr.c	ft_tolower.c\
		ft_toupper.c	ft_memcpy.c		ft_atoi.c\
		ft_strjoin.c	ft_substr.c		ft_strtrim.c\
		ft_itoa.c		ft_putendl_fd.c	ft_putchar_fd.c\
		ft_putstr_fd.c	ft_putnbr_fd.c	ft_strmapi.c\
		ft_split.c		ft_strlen_l_bonus.c	ft_str_rev_bonus.c\
		ft_atoi_base.c


LIST_B =ft_lstnew.c			ft_lstadd_front.c	ft_lstlast.c\
		ft_lstadd_back.c 	ft_lstsize.c		ft_lstdelone.c\
		ft_lstclear.c		ft_lstiter.c		ft_lstmap.c\
		get_next_line_bonus.c get_next_line_utils_bonus.c


OBJ = $(LIST:.c=.o)
OBJ_B = $(LIST_B:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_B) $(HEADER)
	ar rcs $(NAME) $(OBJ) $?
%.o: %.c
	gcc $(FLAGS) -c $< -o $@

bonus: $(OBJ) $(OBJ_B) $(HEADER)
	ar rcs $(NAME) $(OBJ) $(OBJ_B) $(HEADER) $?
clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus