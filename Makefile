NAME = push_swap.a
CC = gcc  # C compiler
CFLAGS = -Wall -Werror -Wextra -I. -c  # C flags
RM = rm -f   # rm command


SRCS = main.c\
srcs/list_crud.c \
srcs/list_iter.c \
srcs/stack_utils.c \
libft/ft_atoi.c \


GNL_SRCS = gnl/get_next_line.c \
gnl/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

GNL_OBJS = $(GNL_SRCS:.c=.o)

all: ${NAME}
	@printf "Makefile starts\n"

$(NAME): $(OBJS) $(GNL_OBJS)
	ar rcs $@ $(OBJS) $(GNL_OBJS)
	$(CC) $(NAME)
# $(OBJS):$(SRCS)
	# $(CC) $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)
	rm a.out
re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re

