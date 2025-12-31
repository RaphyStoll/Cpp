NAME		= Identify

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
LIBFTPP_DIR	= ../../LIBFTPP

SRCS		= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Base.cpp \
			  $(SRC_DIR)/A.cpp \
			  $(SRC_DIR)/B.cpp \
			  $(SRC_DIR)/C.cpp

OBJS		= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(OBJS:.o=.d)

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD -MP
INCLUDES	= -I$(INC_DIR) -I$(LIBFTPP_DIR)/include
LDFLAGS		= -L$(LIBFTPP_DIR) -lftpp -Wl,-rpath,$(LIBFTPP_DIR)

RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFTPP_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
