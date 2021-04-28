




NAME = push_swap.a
CC = gcc  # C compiler
CFLAGS = -Wall -Werror -Wextra -I. -c  # C flags
RM = rm -f   # rm command


SRCS = main.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all: ${NAME}

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

$(B_OBJS):$(B_SRCS)
	$(CC) $(CFLAGS) $(B_SRCS)

bonus: $(OBJS) $(B_OBJS)
	rm -f $(NAME)
	ar rcs $(NAME) $(OBJS) $(B_OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re

