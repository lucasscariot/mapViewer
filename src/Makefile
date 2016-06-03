# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 09:44:59 by lscariot          #+#    #+#              #
#    Updated: 2016/06/01 14:31:48 by lscariot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= fdf

LINK	= ../fdf

CC		= clang

S_DIR	=

O_DIR	=

I_DIR	=

LFLAGS	=  -O3 -g -Wall -Wextra -Werror $(I_DIR) $(LIBS_DIR)

CFLAGS	=  -O3 -g -Wall -Wextra -Werror -lmlx $(I_DIR) $(LIBS_DIR)

FILES	=	main.c								win/ft_win_create.c			\
			parsing/ft_save.c					errors/ft_errors.c			\
			show/ft_draw_line.c					calculs/ft_moves.c			\
			parsing/ft_is.c						show/ft_show.c				\
			show/ft_draw_line.c					show/ft_show_map.c			\
			show/ft_bresenham.c					calculs/ft_key.c			\
			calculs/ft_matrix.c					matrice/ft_rotate.c			\
			matrice/ft_init_mat.c

LIBS_F	= ./libft/libft.a -lncurses ./minilibx/libmlx.a

SRC		= $(addprefix $(S_DIR),$(FILES))

OBJS	= $(addprefix $(O_DIR),$(FILES:.c=.o))

LIBS	= $(addprefix -L. -l,$(LIBS_F))

RM		= rm -f

all: 		$(NAME)

$(NAME): 	$(OBJS)
	@echo ""
	@make -C libft
	@make -C minilibx
	@$(CC) -I./includes $(CFLAGS) -L./minilibx $(LIBS_F) $^ -o $(LINK) -framework OpenGL -framework AppKit
	@echo "\033[32m$(NAME) created.\033[0m"

$(O_DIR)%.o:		$(S_DIR)%.c
	@$(CC) $(LFLAGS) -I./includes -c $< -o $@
	@echo "\033[33m.\033[0m\c"

clean:
	@$(RM) $(OBJS)
	@make -C libft clean
	@make -C minilibx clean

fclean: 	clean
	@$(RM) $(LINK)
	@make -C libft fclean
	@make -C minilibx clean
	@echo "\033[31m$(NAME) cleaned.\033[0m"

re:			fclean all

.PHONY: re clean fclean all
