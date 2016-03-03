# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscariot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 07:22:46 by lscariot          #+#    #+#              #
#    Updated: 2016/03/03 17:34:59 by lscariot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = main.c \
		   ft_hooks.c \
		   ft_error.c \
		   ft_parse.c \
		   ft_draw.c

OBJ_PATH = ./obj/

INC_PATH = ./includes

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -Llib/ -lmlx -framework OpenGL -framework Appkit

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME) :
	mkdir lib/
	make -C minilibx
	make -C libft
	$(CC) $(LFLAGS) $(INC) -o $(NAME) $(SRC_NAME) libft.a

clean:
		make -C libft clean
		make -C minilibx clean
	    rm -fv $(OBJ)
	
fclean: clean
	rm -fv $(NAME)
	rm -rf lib/
	make -C libft fclean
	make -C minilibx fclean

re: fclean all

.PHONY : all clean fclean re
