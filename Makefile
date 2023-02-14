CC = cc

CFLAGS = -Wextra -Wall -Werror

NAME = ft_printf

HEADER = ft_printf.h

SRC = ft_printf.c main.c

OBJ = $(SRC:.c=.o)

%.o: %.c	${HEADER}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re