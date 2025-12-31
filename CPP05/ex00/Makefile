NAME		= Bureaucrat

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

SRCS		= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Bureaucrat.cpp \
			  $(SRC_DIR)/utils.cpp

OBJS		= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(OBJS:.o=.d)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR) -MMD -MP

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
			@mkdir -p $(dir $@)
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

-include $(DEPS)

.PHONY:		all clean fclean re
