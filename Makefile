NAME = rzero.filler

VNAME = poor.visual

SRCF = main.c define_player.c write_field.c manhattan.c read_piece.c found_position.c  libft/get_next_line.c

VSRCF = visual.c libft/get_next_line.c visual_output.c

LIB = libft/libft.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAG) -o $(NAME) $(SRCF) $(LIB)
	$(CC) $(CFLAG) -o $(VNAME) $(VSRCF) $(LIB)

clean:
	make -C libft/ clean
	/bin/rm -f *.o

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	/bin/rm -f $(VNAME)

re: fclean all