# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 17:15:58 by houamrha          #+#    #+#              #
#    Updated: 2024/02/12 19:02:06 by houamrha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
FFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
SRC = ./mandatory/so_long.c ./mandatory/images_check.c ./mandatory/map_check.c ./mandatory/so_long_utils.c ./mandatory/check_map_function_utils.c \
./mandatory/mlx_utils.c ./mandatory/key_pressed_utils.c ./mandatory/so_long_utils_2.c
OBJ = $(SRC:.c=.o)
SRCB = ./bonus/so_long_bonus.c ./bonus/images_check_bonus.c ./bonus/map_check_bonus.c ./bonus/so_long_utils_bonus.c ./bonus/check_map_function_utils_bonus.c \
./bonus/mlx_utils_bonus.c ./bonus/key_pressed_utils_bonus.c ./bonus/so_long_utils_2_bonus.c ./bonus/animate_player.c ./bonus/animate_enemy.c
OBJB = $(SRCB:.c=.o)
GNLS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNLO = $(GNLS:.c=.o)
LBS = ./Libft/ft_putchar_fd.c ./Libft/ft_putendl_fd.c ./Libft/ft_putnbr_fd.c ./Libft/ft_putstr_fd.c ./Libft/ft_strlen.c ./Libft/ft_strncmp.c ./Libft/ft_itoa.c ./Libft/ft_strdup.c
LBO = $(LBS:.c=.o)
HEADER = ./mandatory/so_long.h
HEADER_BONUS = ./bonus/so_long_bonus.h
GN_HEADER = ./get_next_line/get_next_line.h
LF_HEADER = ./Libft/libft.h

all: $(NAME)

$(NAME): $(OBJ) $(LBO) $(GNLO)
	$(CC) $(OBJ) $(LBO) $(GNLO) $(FFLAGS) -o $(NAME)

bonus: $(OBJB) $(LBO) $(GNLO)
	$(CC) $(OBJB) $(LBO) $(GNLO) $(FFLAGS) -o $(NAME)

./Libft/%.o: ./Libft/%.c $(LF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

./get_next_line/%.o: ./get_next_line/%.c $(GN_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

./mandatory/%.o: ./mandatory/%.c $(HEADER) $(GN_HEADER) $(LF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/%.o: ./bonus/%.c $(HEADER_BONUS) $(GN_HEADER) $(LF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f $(OBJB)
	rm -f $(GNLO)
	rm -f $(LBO)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean