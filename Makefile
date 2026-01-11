BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
LIGHT_GRAY = \033[1;90m
LIGHT_RED = \033[1;91m
LIGHT_GREEN = \033[1;92m
LIGHT_YELLOW = \033[1;93m
LIGHT_BLUE = \033[1;94m
LIGHT_MAGENTA = \033[1;95m
LIGHT_CYAN = \033[1;96m
LIGHT_WHITE = \033[1;97m

RESET = \033[0m
BOLD = \033[1m
FAINT = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
RAPID_BLINK = \033[6m
REVERSE = \033[7m
CROSSED = \033[9m

NC = \033[0m

MAKE_CMD = make -C

CPP00 = CPP00/ex0
CPP01 = CPP01/ex0
CPP02 = CPP02/ex0
CPP03 = CPP03/ex0
CPP04 = CPP04/ex0
CPP05 = CPP05/ex0
CPP06 = CPP06/ex0
CPP07 = CPP07/ex0
CPP08 = CPP08/ex0
CPP09 = CPP09/ex0



CPP00:
	@echo "$(LIGHT_BLUE)🔨 Building CPP00...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP00)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP00)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP00)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP00 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP00 done!$(RESET)\n"; \
	fi

CPP01:
	@echo "$(LIGHT_BLUE)🔨 Building CPP01...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP01)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP01)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP01)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex03...$(RESET)"; $(MAKE_CMD) $(CPP01)3 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex03 done$(RESET)" || { echo "  $(RED)✗ ex03 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex04...$(RESET)"; $(MAKE_CMD) $(CPP01)4 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex04 done$(RESET)" || { echo "  $(RED)✗ ex04 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex05...$(RESET)"; $(MAKE_CMD) $(CPP01)5 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex05 done$(RESET)" || { echo "  $(RED)✗ ex05 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex06...$(RESET)"; $(MAKE_CMD) $(CPP01)6 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex06 done$(RESET)" || { echo "  $(RED)✗ ex06 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP01 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP01 done!$(RESET)\n"; \
	fi

CPP02:
	@echo "$(LIGHT_BLUE)🔨 Building CPP02...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP02)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP02)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP02)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex03...$(RESET)"; $(MAKE_CMD) $(CPP02)3 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex03 done$(RESET)" || { echo "  $(RED)✗ ex03 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP02 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP02 done!$(RESET)\n"; \
	fi

CPP03:
	@echo "$(LIGHT_BLUE)🔨 Building CPP03...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP03)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP03)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP03)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex03...$(RESET)"; $(MAKE_CMD) $(CPP03)3 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex03 done$(RESET)" || { echo "  $(RED)✗ ex03 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP03 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP03 done!$(RESET)\n"; \
	fi

CPP04:
	@echo "$(LIGHT_BLUE)🔨 Building CPP04...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP04)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP04)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP04)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex03...$(RESET)"; $(MAKE_CMD) $(CPP04)3 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex03 done$(RESET)" || { echo "  $(RED)✗ ex03 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP04 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP04 done!$(RESET)\n"; \
	fi

CPP05:
	@echo "$(LIGHT_BLUE)🔨 Building CPP05...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP05)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP05)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP05)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex03...$(RESET)"; $(MAKE_CMD) $(CPP05)3 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex03 done$(RESET)" || { echo "  $(RED)✗ ex03 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP05 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP05 done!$(RESET)\n"; \
	fi

CPP06:
	@echo "$(LIGHT_BLUE)🔨 Building CPP06...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP06)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP06)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP06)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP06 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP06 done!$(RESET)\n"; \
	fi

CPP07:
	@echo "$(LIGHT_BLUE)🔨 Building CPP07...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP07)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP07)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP07)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP07 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP07 done!$(RESET)\n"; \
	fi

CPP08:
	@echo "$(LIGHT_BLUE)🔨 Building CPP08...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP08)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP08)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP08)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP08 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP08 done!$(RESET)\n"; \
	fi

CPP09:
	@echo "$(LIGHT_BLUE)🔨 Building CPP09...$(RESET)"
	@failed=0; \
	echo "  $(CYAN)→ Compiling ex00...$(RESET)"; $(MAKE_CMD) $(CPP09)0 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex00 done$(RESET)" || { echo "  $(RED)✗ ex00 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex01...$(RESET)"; $(MAKE_CMD) $(CPP09)1 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex01 done$(RESET)" || { echo "  $(RED)✗ ex01 failed$(RESET)"; failed=1; }; \
	echo "  $(CYAN)→ Compiling ex02...$(RESET)"; $(MAKE_CMD) $(CPP09)2 > /dev/null 2>&1 && echo "  $(GREEN)✓ ex02 done$(RESET)" || { echo "  $(RED)✗ ex02 failed$(RESET)"; failed=1; }; \
	if [ $$failed -eq 1 ]; then \
		echo "$(LIGHT_RED)❌ CPP09 failed!$(RESET)\n"; \
	else \
		echo "$(LIGHT_GREEN)✅ CPP09 done!$(RESET)\n"; \
	fi

all: CPP00 CPP01 CPP02 CPP03 CPP04 CPP05 CPP06 CPP07 CPP08 CPP09

clean:
	@echo "$(YELLOW)🧹 Cleaning all exercises...$(RESET)"
	@find CPP* -name Makefile -execdir make clean \; 2>/dev/null || true
	@echo "$(LIGHT_GREEN)✅ Clean done!$(RESET)"

fclean:
	@echo "$(RED)🗑️  Deep cleaning all exercises...$(RESET)"
	@find CPP* -name Makefile -execdir make fclean \; 2>/dev/null || true
	@echo "$(LIGHT_GREEN)✅ Fclean done!$(RESET)"

re: fclean all

pull-libftpp:
	git fetch libftpp
	git subtree pull --prefix=lib/LIBFTPP libftpp main --squash

push-libftpp:
	git subtree push --prefix=lib/LIBFTPP libftpp main


.PHONY: all clean fclean re \
		CPP00 CPP01 CPP02 CPP03 CPP04 CPP05 CPP06 CPP07 CPP08 CPP09