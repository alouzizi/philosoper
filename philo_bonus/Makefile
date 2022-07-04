NAME = philo_bonus

SRC = philo_bonus.c \
	   utils_bonus.c \
	   utils2_bonus.c \

CC = cc 

HEADER = philo_bonus.h 

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

all : $(NAME)
$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
fclean : clean
	@rm -f $(NAME)

re : fclean all