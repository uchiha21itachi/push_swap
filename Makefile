NAME = push_swap.a
CC = gcc  # C compiler
CFLAGS = -Wall -Werror -Wextra -I. -c  # C flags
RM = rm -f   # rm command


SRCS = srcs/push_swap.c\
srcs/stack_init.c \
srcs/list_crud.c \
srcs/executor.c \
srcs/creator.c \
srcs/partition.c \
srcs/partition_helpers.c \
srcs/create_hundred_moves.c \
srcs/create_hundred_helpers.c \
srcs/creator_helpers.c \
srcs/free.c \
srcs/libft_utils.c \
srcs/print_all.c \
 

GNL_SRCS = gnl/get_next_line.c \
gnl/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

GNL_OBJS = $(GNL_SRCS:.c=.o)

all: ${NAME}
	@printf "Makefile starts\n"

$(NAME): $(OBJS) $(GNL_OBJS)
	ar rcs $@ $(OBJS) $(GNL_OBJS)
	$(CC) $(NAME) -o push_swap
# $(OBJS):$(SRCS)
	# $(CC) $(CFLAGS) $(SRCS)

clean:
	$(RM) $(OBJS) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)
	rm push_swap
re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re

