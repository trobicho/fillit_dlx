CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
SRCS = fillitTest.c dlx.c fifo.c matrix_create.c qlist.c
HDRS = dlx.h fifo.h matrix_create.h qlist.h
OUTS = $(SRCS:.c=.o)
NAME = dlxTest

all: $(NAME)

$(NAME): $(OUTS)
	$(CC) $(OUTS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
