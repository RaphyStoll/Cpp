NAME = PmergeMe
CC = c++ -DDEBUG
CPP_FLAGS = -Werror -Wall -Wextra -std=c++98
INCLUDE = includes
LIBFTPP_DIR = ../../LIBFTPP
LIBFTPP_INCLUDE = $(LIBFTPP_DIR)/include
LIBFTPP_LIB = $(LIBFTPP_DIR)/libftpp.a
UNAME_S := $(shell uname -s)
SRC = main.cpp

ifeq ($(UNAME_S),Darwin)
    LIBFTPP_SHARED = $(LIBFTPP_DIR)/libftpp.dylib
else
    LIBFTPP_SHARED = $(LIBFTPP_DIR)/libftpp.so
endif


all: $(LIBFTPP_LIB)
	$(CC) $(CPP_FLAGS) $(SRC) -I$(INCLUDE) -I$(LIBFTPP_INCLUDE) $(LIBFTPP_LIB) -o $(NAME)

$(LIBFTPP_LIB):
	@echo "Compilation de LIBFTPP..."
	@make -C $(LIBFTPP_DIR) 

shared: $(LIBFTPP_SHARED)
	$(CC) $(CPP_FLAGS) $(SRC) -I$(INCLUDE) -I$(LIBFTPP_INCLUDE) -L$(LIBFTPP_DIR) -lftpp -o $(NAME)

$(LIBFTPP_SHARED):
	@echo "Compilation de LIBFTPP en bibliothèque partagée..."
	@make -C $(LIBFTPP_DIR) dev

clean:
	rm -f $(NAME)
	@make -C $(LIBFTPP_DIR) clean

fclean: clean
	@make -C $(LIBFTPP_DIR) fclean

re: fclean all

.PHONY: all re clean fclean shared