SOURCES = instructions.c print.c 2_merge_sort.c 1_radix.c 0_selection_sort.c 3_turk_sort.c

MAIN_SRC = push_swap.c

TEST_SRC = test.c

NAME = a.out

CC = gcc

LIBPATH = libft/
LIBRARY = $(LIBPATH)libft.a

CFLAGS = -Wall -Wextra -Werror
SAN = -fsanitize=address -g

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(MAIN_SRC) $(LIBRARY) -o $(NAME)

clean:
	rm -f $(NAME)

debug: $(SOURCES)
	$(CC) $(CFLAGS) $(SAN) $(MAIN_SRC) $(SOURCES) $(LIBRARY) -o $(NAME)

test: $(SOURCES)
	$(CC) $(CFLAGS) $(SAN) $(SOURCES) $(TEST_SRC) $(LIBRARY) -o $(NAME)

re: clean
	$(CC) $(CFLAGS) $(SOURCES)

all: $(NAME)

fclean: clean
	rm -f $(NAME)