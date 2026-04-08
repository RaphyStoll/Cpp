NAME = PmergeMe
CC = c++
CPP_FLAGS = -Werror -Wall -Wextra -std=c++98 -MMD -MP
INCLUDE = includes
OBJ_DIR = obj
LIBFTPP_DIR = ../../LIBFTPP
LIBFTPP_INCLUDE = $(LIBFTPP_DIR)/include
LIBFTPP_LIB = $(LIBFTPP_DIR)/libftpp.a
UNAME_S := $(shell uname -s)
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

ifeq ($(UNAME_S),Darwin)
    LIBFTPP_SHARED = $(LIBFTPP_DIR)/libftpp.dylib
    RANDOM_CMD = jot -r 10 1 100000
else
    LIBFTPP_SHARED = $(LIBFTPP_DIR)/libftpp.so
    RANDOM_CMD = shuf -i 1-100000 -n 10
endif


all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPP_LIB)
	$(CC) $(CPP_FLAGS) $(OBJ) -I$(INCLUDE) -I$(LIBFTPP_INCLUDE) $(LIBFTPP_LIB) -o $(NAME)


$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPP_FLAGS) -I$(INCLUDE) -I$(LIBFTPP_INCLUDE) -c $< -o $@

$(LIBFTPP_LIB):
	@echo "Compilation de LIBFTPP..."
	@make -C $(LIBFTPP_DIR) 

shared: $(LIBFTPP_SHARED)
	$(CC) $(CPP_FLAGS) $(SRC) -I$(INCLUDE) -I$(LIBFTPP_INCLUDE) -L$(LIBFTPP_DIR) -lftpp -o $(NAME)

$(LIBFTPP_SHARED):
	@echo "Compilation de LIBFTPP en bibliothèque partagée..."
	@make -C $(LIBFTPP_DIR) dev

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFTPP_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTPP_DIR) fclean

test_%: $(NAME)
	@echo "Lancement du test avec $* nombres aléatoires..."
	@if [ "$(UNAME_S)" = "Darwin" ]; then \
		./$(NAME) `jot -r $* 1 100000 | tr '\n' ' '`; \
	else \
		./$(NAME) `shuf -i 1-100000 -n $* | tr '\n' ' '`; \
	fi

re:
	@$(MAKE) fclean
	@$(MAKE) all

compdb:
	bear -- $(MAKE) re

.PHONY: all re clean fclean shared compdb