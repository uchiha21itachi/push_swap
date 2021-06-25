NAME = push_swap.a
NAME_B = checker.a
CC = gcc  # C compiler
CFLAGS = -Wall -Werror -Wextra -I.   # C flags
RM = rm -f   # rm command


SRCS = srcs/push_swap.c\
srcs/moves_creator.c \
srcs/partition.c \
srcs/create_hundred_moves.c \
srcs/create_hundred_helpers.c \
 
COM_SRCS = srcs/stack_init.c \
srcs/moves_init.c \
srcs/list_crud.c \
srcs/executor.c \
srcs/executor_helpers.c \
srcs/free.c \
srcs/libft_utils.c \
srcs/utils.c \



GNL_SRCS = gnl/get_next_line.c \
gnl/get_next_line_utils.c \

BONUS_SRCS = srcs/checker.c \


OBJS = $(SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
COM_OBJS = $(COM_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


all: ${NAME}
	@printf "Makefile starts\n"

$(NAME): $(OBJS) $(GNL_OBJS) $(COM_OBJS)
	ar rcs $@ $(OBJS) $(GNL_OBJS) $(COM_OBJS)
	$(CC) $(CFLAGS) $(NAME) -o push_swap

bonus: $(NAME_B)
	@printf "BONUS make starts\n"

$(NAME_B): $(BONUS_OBJS) $(GNL_OBJS) $(COM_OBJS)
	ar rcs $@ $(BONUS_OBJS) $(GNL_OBJS) $(COM_OBJS)
	$(CC) $(CFLAGS) $(NAME_B) -o checker

clean:
	$(RM) $(OBJS) $(GNL_OBJS) $(COM_OBJS) 

fclean: clean
	rm -f $(NAME)
	rm push_swap

re: fclean all

bclean: 
	$(RM) $(BONUS_OBJS)
	rm -f $(NAME_B)
	rm checker



# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re
