NAME = account

CC = c++ -std=c++98
CPP_FLAG = -Wall -Wextra -Werror

SRC = 	src/tests.cpp \
		src/Account.cpp \
		src/utils/print_debug.cpp

all:
	$(CC) $(CPP_FLAG) $(SRC) -Iinclude -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re clean fclean
