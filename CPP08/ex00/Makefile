GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m

NAME = Span

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

LIBFT_DIR = ../../LIBFTPP
LIBFT_A = $(LIBFT_DIR)/libftpp.a
INCFLAGS = -I include -I $(LIBFT_DIR)/include

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(shell find $(SRC_DIR) -name "*.cpp")
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

TOTAL_OBJS  = $(words $(SRCS))
PROGRESS_FILE = $(OBJ_DIR)/.progress
PROGBAR_LEN = 40

RM = rm -rf

all : $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@if [ -z "$(strip $(OBJS))" ]; then \
		echo "Error: no sources found in $(SRC_DIR)/ (*.cpp)."; \
		echo "Hint: add at least $(SRC_DIR)/main.cpp with an int main()."; \
		exit 1; \
	fi
	@echo "$(GREEN)[Webserv] All objects compiled!$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@echo "$(GREEN)all is DONE$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $(INCFLAGS) -c $< -o $@
	@count=$$(cat $(PROGRESS_FILE) 2>/dev/null || echo 0); \
	total=$(TOTAL_OBJS); [ $$total -le 0 ] && total=1; \
	[ $$count -ge $$total ] && count=0; \
	count=$$((count+1)); echo $$count > $(PROGRESS_FILE); \
	percent=$$(( (count*100)/total )); \
	bar_len=$(PROGBAR_LEN); filled=$$(( (percent*bar_len)/100 )); \
	bar=""; i=0; while [ $$i -lt $$filled ]; do bar="$$bar#"; i=$$((i+1)); done; \
	printf "\r[%-*s] %3d%% (%d/%d) Compiling: %s" $$bar_len "$$bar" $$percent $$count $$total "$<"; \
	[ $$count -eq $$total ] && printf "\n" || true

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) static


clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo "\033[32m[webserv] Clean done!\033[0m"

fclean: clean
	@echo "$(RED)Cleaning executable and libraries...$(NC)"
	$(RM) $(NAME)  $(TEST_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@echo "\033[32m[webserv] Full clean done!\033[0m"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re