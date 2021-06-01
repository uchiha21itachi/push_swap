NAME = push_swap.a
CC = gcc  # C compiler
CFLAGS = -Wall -Werror -Wextra -I. -c  # C flags
RM = rm -f   # rm command


SRCS = srcs/push_swap.c\
srcs/stack_init.c \
srcs/list_crud.c \
srcs/executor.c \
srcs/free.c \
srcs/print_all.c \

LIBFT_SRCS = libft/ft_atoi.c \
libft/ft_strncmp.c \
 

GNL_SRCS = gnl/get_next_line.c \
gnl/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

GNL_OBJS = $(GNL_SRCS:.c=.o)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: ${NAME}
	@printf "Makefile starts\n"

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT_OBJS)
	ar rcs $@ $(OBJS) $(GNL_OBJS) $(LIBFT_OBJS)
	$(CC) $(NAME) -o push_swap
# $(OBJS):$(SRCS)
	# $(CC) $(CFLAGS) $(SRCS)

clean:
	$(RM) $(OBJS) $(GNL_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)
	rm push_swap
re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re

