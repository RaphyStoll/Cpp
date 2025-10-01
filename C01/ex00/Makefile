CC = c++
CPP_FLAG = -Wall -Werror -Wextra

SRC = $(wildcard src/*.cpp)

all:
	$(CC) $(CPP_FLAG) $(SRC) -Iinclude -o $(NAME)

clean:
	rm -f $(NAME)

re:
	clean all

.PHONY: all re clean