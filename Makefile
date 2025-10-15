NAME	:= bsq
SRC_DIR := src
INC_DIR := include

SRCS := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/ft_create_map.c \
	$(SRC_DIR)/ft_get_matrix.c \
	$(SRC_DIR)/ft_process_map.c \
	$(SRC_DIR)/ft_util.c

OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/bsq.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
