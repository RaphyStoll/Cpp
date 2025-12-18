SUBDIRS = LIBFTPP ex00 ex01 ex02 ex03

.PHONY: all clean fclean re

all:
	@for dir in $(SUBDIRS); do \
		echo "---- Compilation de $$dir ----"; \
		$(MAKE) -C $$dir || exit 1; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo "---- Clean $$dir ----"; \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		echo "---- Fclean $$dir ----"; \
		$(MAKE) -C $$dir fclean; \
	done

re:
	@for dir in $(SUBDIRS); do \
		echo "---- Rebuild $$dir ----"; \
		$(MAKE) -C $$dir re; \
	done