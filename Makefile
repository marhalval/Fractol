# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 20:34:17 by hvashchu          #+#    #+#              #
#    Updated: 2017/09/26 20:34:20 by hvashchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC	= 	main.c \
		draw.c \
		flows.c \
		julia.c \
		mandelbrot.c \
		mouse.c \
		keyboard.c

OBJ = $(SRC:.c=.o)
FLAGS = -framework OpenGL -framework AppKit -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx/ 
	make -C libft/
	gcc -o $(NAME) $(OBJ) libft/*.o minilibx/*.o $(FLAGS)
	@echo fractol has been made

%.o: %.c
	gcc -c -o  $@ $<

cleanlib:
	make clean -C ./libft
	make clean -C ./minilibx

fcleanlib:
	make fclean -C ./libft
	make clean -C ./minilibx

clean: cleanlib
	rm -f $(OBJ)
	@echo *.o have been cleaned.

fclean: clean fcleanlib
	rm -f $(NAME)
	@echo *.a and *.o have been cleaned.

re: fclean all
