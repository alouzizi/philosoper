NAME = philo

SRC  =	philo.c \
		args.c   \
		utils.c   \

CC = cc 

HEADER = philo.h 

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
