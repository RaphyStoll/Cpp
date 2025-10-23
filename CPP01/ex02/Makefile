NAME = Brain
CC = c++
CPP_FLAGS =  -Werror -Wall -Wextra
INCLUDE = include


SRC = $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp)

all: 
	$(CC) $(CPP_FLAGS) $(SRC) -Iinclude -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY : all re clean