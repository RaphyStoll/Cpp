NAME = Harl
CC = c++
CPP_FLAGS = -Werror -Wall -Wextra -std=c++98
INCLUDE = include


SRC = $(wildcard *.cpp)

all:
	$(CC) $(CPP_FLAGS) $(SRC) -Iinclude -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re clean fclean