NAME := philo

SRCS := main.c
SRCS += ft_strlen.c \
		put_str_fd.c \
		ft_atof.c \
		ft_atoi.c \
		ft_strtod.c \

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
