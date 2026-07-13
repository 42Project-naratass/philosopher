NAME := philo
DEBUG := philo_debug

SRCS := main.c

SRCS += action/philo_usleep.c \
		action/simulate_stop.c \
		action/one_philo.c \
		action/two_philos.c \
		action/routine.c \
		action/philo_usleep.c \

SRCS += parser/data_init.c \
		parser/check_nums.c \

SRCS += time/elapsed_time.c \
		time/get_time.c \

SRCS +=	message/print_status.c \
		message/error_exit.c \

SRCS += utils/ft_strlen.c \
		utils/ft_putstr_fd.c \
		utils/ft_atoi.c \
		utils/is_digit.c \
		utils/is_space.c \
		utils/ft_memcpy.c \
		utils/mutex_mode.c \
		utils/thread_mode.c \

SRCS += simulate/monitor.c \
		simulate/philo_simulate.c \

SRCS += clean_up/ft_free.c \
		clean_up/clear_data.c \

OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Werror -Wextra
DFLAGS := -g -fsanitize=address -fsanitize=undefined -pthread

INCLUDE = -I ./includes/

%.o: %.c
	cc -c $(CFLAGS) $(INCLUDE) $< -o $@

$(NAME): $(OBJS)
	cc $(CFLAGS) $(INCLUDE) $^ -o $@

$(DEBUG): $(OBJS)
	cc $(CFLAGS) $(DFLAGS) $(INCLUDE) $^ -o $@

all: $(NAME)

debug: $(DEBUG)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(DEBUG)

re: fclean all

.PHONY: all clean fclean re debug
