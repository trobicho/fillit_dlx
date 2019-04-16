CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
SRCS = newfillTest.c mega_dlx.c fillit_init.c dlx.c fifo.c matrix_create.c qlist.c
HDRS = mega_dlx.h dlx.h fillit_init.h fifo.h matrix_create.h qlist.h
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
