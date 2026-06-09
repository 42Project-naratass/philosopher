NAME := philo

SRCS := main.c

OBJS := $(SRCS.c=.o)

CFLAGS := -Wall -Werro -Wextra
CFLAGS += -g3 -fsanitized=address,undefined

INCLUDE = -I .

%.o:%.c philo.h
	cc $(CFLAGS) $(INCLUDE) -c $^ -o $@

$(NAME): $(OBJS)
	cc $(CFLAGS) $(INCLUDE) -c $^ -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
