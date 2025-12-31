NAME		= 28B

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
LIBFTPP_DIR	= ../../LIBFTPP

SRCS		= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Bureaucrat.cpp \
			  $(SRC_DIR)/AForm.cpp \
			  $(SRC_DIR)/ShrubberyCreationForm.cpp \
			  $(SRC_DIR)/RobotomyRequestForm.cpp \
			  $(SRC_DIR)/PresidentialPardonForm.cpp

OBJS		= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(OBJS:.o=.d)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR) -I$(LIBFTPP_DIR)/include -MMD -MP
LDFLAGS		= -L$(LIBFTPP_DIR) -lftpp -Wl,-rpath,$(LIBFTPP_DIR)

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

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
