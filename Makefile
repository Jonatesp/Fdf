# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 21:31:25 by anbourge          #+#    #+#              #
#    Updated: 2021/12/01 14:36:52 by anbourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

_SRCS = ft_parsing.c ft_window_create.c ft_fdf.c gnl/get_next_line.c \
gnl/get_next_line_utils.c ft_pixel_print.c ft_algo_utils.c \
ft_pixel_print_utils.c ft_pixel_print_utils2.c

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
SRCO = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=42 -Imlx
INC = -I includes/

all : $(NAME)

$(NAME) : $(SRCO)
	make -C libft
	make -C mlx
	gcc -o $(NAME) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCO)

%.o : %.c
	gcc $(FLAG) -o $(NAME) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO)
	make clean -C libft
	make clean -C mlx

fclean : clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a
	/bin/rm -f mlx/libmlx.a

re :
	make fclean
	make