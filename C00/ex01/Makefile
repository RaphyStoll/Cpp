NAME =PhoneBook

CC = c++ -std=c++98
CPP_FLAG = -Wall -Wextra -Werror

SRC = 	src/main.cpp \
		src/add.cpp \
		src/contact_getter.cpp \
		src/contact_setter.cpp \
		src/contact.cpp \
		src/search.cpp \
		src/phonebook.cpp \
		src/utils/print_debug.cpp

all:
	$(CC) $(CPP_FLAG) $(SRC) -Iinclude -o $(NAME)

clean:
	rm -f $(NAME)

re:
	clean all

.PHONY: all re clean