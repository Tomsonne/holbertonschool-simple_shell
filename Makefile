CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
SRC = main.c utils.c
OBJ = $(SRC:.c=.o)
NAME = mini_shell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
