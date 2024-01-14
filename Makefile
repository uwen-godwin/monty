CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

monty: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o monty

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f monty

re: fclean monty

