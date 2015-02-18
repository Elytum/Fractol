#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 14:37:48 by achazal           #+#    #+#              #
#    Updated: 2015/01/29 14:37:51 by achazal          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CC = gcc

SRC = ft_init.c \
		ft_keypress.c \
		ft_fractals.c \
		ft_init_fract.c \
		ft_images.c \
		ft_fractals2.c

CFLAGS = -Wall -Werror -Wextra -I ./includes -I /usr/X11/include -Ofast

MLXFLAGS = -L/usr/X11/lib -lmlx -lX11 -lXext

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(SRC) -L libft -lft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
	@make re -C libft

.PHONY: all, fclean, clean, re 
