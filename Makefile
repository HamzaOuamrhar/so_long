CC = cc
CFLAGS = -Wall -Wextra -Werror
FFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
LIBFT = ./Libft/libft.a
library = ./mandatory/so_long.h
SRC = ./mandatory/so_long.c ./mandatory/images_check.c ./mandatory/map_check.c ./mandatory/so_long_utils.c
OBJ = $(SRC:.c=.o)
GNLS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNL = $(GNLS:.c=.o)

all: libft $(NAME)

libft: $(LIBFT)

$(LIBFT):
	make -C Libft

$(NAME): $(OBJ) $(LIBFT) $(GNL)
	$(CC) $(OBJ) $(LIBFT) $(GNL) $(FFLAGS) -o $(NAME)

%.o: %.c
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