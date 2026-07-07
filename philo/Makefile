NAME := philo
DEBUG := philo_debug

SRCS := main.c \
		data_init.c

SRCS := action/philo_usleep.c \
		action/simulate_stop.c \
		action/one_philo.c \
		action/two_philos.c \

SRCS := parser/data_init.c \
		parser/check_nums.c \

SRCS := time/elapsed_time.c \
		time/get_time.c \

SRCS += utils/ft_strlen.c \
		utils/ft_putstr_fd.c \
		utils/ft_atoi.c \
		utils/is_digit.c \
		utils/is_space.c \
		utils/ft_exit.c \
		utils/ft_memcpy.c \
		utils/ft_free.c \
		utils/clear_data.c \
		utils/philo_usleep.c \
		utils/print_status.c \

SRCS += err_handle/error_exit.c \

SRCS += simulate/monitor.c \
		simulate/philo_simulate.c \

OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Werror -Wextra
DFLAGS := -g3 -pthread 

INCLUDE = -I /includes

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
