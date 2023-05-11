# NAME = gnl

# CC = cc 

# CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

# SRC = get_next_line_utils.c get_next_line.c main.c

# OBJ = $(SRC:.c=.o)

# all:	$(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $^ -o $@

# clean:
# 	rm -f *.o

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# test: re
# 	./gnl

# .PHONY: clean all fclean re test