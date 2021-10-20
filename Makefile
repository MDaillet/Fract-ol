# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 16:58:20 by mdaillet          #+#    #+#              #
#    Updated: 2021/07/09 18:10:38 by mdaillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fract-ol

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g3 -O0

SRCS = srcs/main.c \
	   srcs/ft_init.c \
	   srcs/ft_key_hook.c \
	   srcs/ft_mouse_hook.c \
	   srcs/ft_put_string.c \
	   srcs/ft_axone.c \
	   srcs/ft_julia.c \
	   srcs/ft_mandelbrot.c \
	   srcs/ft_put_pxl.c


OBJS	=	$(SRCS:.c=.o)

LIBS	=	-lm -Llibft -lft -Lminilibx -lmlx -lXext -lX11

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			make -C minilibx
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
			@echo "Compilation done !"

bonus: $(NAME)
					
clean:
			make -C libft clean
			make -C minilibx clean
			rm -rf $(OBJS)

fclean:		clean
			make -C libft fclean
			make -C minilibx fclean
			rm -rf $(NAME)
			@echo "Cleaning done !"

norme:
			norminette inc
			norminette srcs
			norminette libft
			@echo "Norme done !"

re:			fclean all

.PHONY:		all clean fclean norme re
