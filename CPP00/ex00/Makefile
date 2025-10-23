NAME = megaphone

CC = c++ -std=c++98
CPP_FLAG = -Wall -Wextra -Werror

all:
	$(CC) $(CPP_FLAG) megaphone.cpp -o $(NAME)

clean:
	rm -f $(NAME)

re:
	clean all

.PHONY: all re clean