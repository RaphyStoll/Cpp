NAME = BraiiiiiiinnnzzzZ

CC = c++
CPP_FLAG = -Wall -Werror -Wextra

SRC = $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp)

all:
	$(CC) $(CPP_FLAG) $(SRC) -Iinclude -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re clean fclean