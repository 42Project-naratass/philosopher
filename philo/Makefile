NAME := philo

SRCS := main.c
SRCS += utils/ft_strlen.c \
		utils/putstr_fd.c \
		utils/ft_atof.c \
		utils/ft_atoi.c \
		utils/ft_strtod.c \
		utils/is_digit.c \
		utils/is_space.c \
		utils/check_nums.c \
		utils/ft_exit.c \
		utils/ft_memcpy.c

SRCS += err_handle/thread_err.c \

SRCS += simulate/philo_simulate.c \
		simulate/philo.c

OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Werror -Wextra
CFLAGS += -g3 -fsanitize=address,undefined

INCLUDE = -I.

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) | philo.h err.h
	cc $(CFLAGS) $(INCLUDE) $^ -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
