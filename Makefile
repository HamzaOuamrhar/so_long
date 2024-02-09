# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 17:15:58 by houamrha          #+#    #+#              #
#    Updated: 2024/02/09 23:30:41 by houamrha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
FFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
LIBFT = ./Libft/libft.a
library = ./mandatory/so_long.h
SRC = ./mandatory/so_long.c ./mandatory/images_check.c ./mandatory/map_check.c ./mandatory/so_long_utils.c ./mandatory/check_map_function_utils.c \
./mandatory/mlx_utils.c ./mandatory/key_pressed_utils.c ./mandatory/so_long_utils_2.c
OBJ = $(SRC:.c=.o)
GNLS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNL = $(GNLS:.c=.o)
HEADER = ./mandatory/so_long.h
GN_HEADER = ./get_next_line/get_next_line.h
LF_HEADER = ./Libft/libft.h

all: libft $(NAME)

libft: $(LIBFT)

$(LIBFT): $(LF_HEADER)
	make -C Libft

$(NAME): $(OBJ) $(LIBFT) $(GNL)
	$(CC) $(OBJ) $(LIBFT) $(GNL) $(FFLAGS) -o $(NAME)

./mandatory/%.o: ./mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

./get_next_line/%.o: ./get_next_line/%.c $(GN_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

get_next_line/%.o: get_next_line/%.C
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -r $(GNL)
	make -C Libft clean

fclean : clean
	rm -f $(NAME)
	make -C Libft fclean

re: fclean all

.PHONY: clean