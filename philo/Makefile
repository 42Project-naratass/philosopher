NAME := philo
DEBUG := philo_debug

SRCS := main.c \
				data_init.c

SRCS += utils/ft_strlen.c \
				utils/putstr_fd.c \
				utils/ft_atof.c \
				utils/ft_atoi.c \
				utils/ft_strtod.c \
				utils/is_digit.c \
				utils/is_space.c \
				utils/check_nums.c \
				utils/ft_exit.c \
				utils/ft_memcpy.c \
				utils/get_time.c \
				utils/ft_free.c \
				utils/clear_data.c \
				utils/elapsed_time.c \
				utils/ft_usleep.c

SRCS += err_handle/thread_err.c \

SRCS += simulate/philo_simulate.c \
				simulate/philo.c \
				simulate/monitor.c \
				simulate/log_display.c \

OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Werror -Wextra
DFLAGS := -g3 -pthread 

INCLUDE = -I.

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) | philo.h err.h
	cc $(CFLAGS) $(INCLUDE) $^ -o $@

$(DEBUG): $(OBJS) | philo.h err.h
	cc $(CFLAGS) $(DFLAGS) $(INCLUDE) $^ -o $@

all: $(NAME)

debug: $(DEBUG)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(DEBUG)

re: fclean all

.PHONY: all clean fclean re
