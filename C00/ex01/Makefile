NAME =PhoneBook

CC = c++ -std=c++98
CPP_FLAG = -Wall -Wextra -Werror

SRC = 	src/main.cpp \
		src/add.cpp \
		src/contact_helper.cpp \
		src/pb_helper.cpp \
		src/search.cpp

all:
	$(CC) $(CPP_FLAG) $(SRC) -Iinclude -o $(NAME)

clean:
	rm -f $(NAME)

re:
	clean all

.PHONY: all re clean