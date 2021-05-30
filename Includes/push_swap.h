#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../gnl/get_next_line.h"

typedef struct	s_move
{
	char			*mov;
	int				mov_num;
	struct	s_move	*next;
}				t_move;

typedef struct	s_node
{
	int				number;
	struct	s_node	*next;
	struct	s_node	*previous;
}				t_node;

typedef	struct s_stack
{
	struct 	s_node	*node;
	struct	s_move	*moves;
	int				length;
}				t_stack;

t_node			*ft_lstnew(int content);
void			ft_lstadd_front(t_stack *stack, t_node *new);
int				ft_lstsize(t_node *lst);
t_node			*ft_lstlast(t_node *lst);
void			ft_lstadd_back(t_stack *stack, t_node *new);
int				ft_atoi(const char *str);
char			*remove_space_digit(char *line, char c);
t_stack			*stack_init(void);
void			fill_stack(char **argv, t_stack *stack);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			exec(char *ins, t_stack *stackA, t_stack *stackB);
void			print_stack(t_stack *stack);
void			print_numbers(t_node *list, char x);
void			print_both(t_node *stackA, t_node *stackB);
void			free_stack(t_stack *stack);


#endif

