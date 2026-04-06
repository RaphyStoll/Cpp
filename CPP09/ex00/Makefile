NAME = btc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = obj

SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)


$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
