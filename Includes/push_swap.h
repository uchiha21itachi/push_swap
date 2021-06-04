#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../gnl/get_next_line.h"

typedef struct	s_move
{
	char			*ins;
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
	struct  s_move	*moves;
	int				length;
}				t_stack;

typedef	struct s_data
{
	int		min;
	int		min_pos;
	int		max;
	int		max_pos;
	int		med;
	int		med_pos;
}				t_data;


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
void			free_all(t_stack *stackA, t_stack *stackB);
int				ft_toupper(int c);
void			update_moves(t_stack *stackA, char *ins);
void			free_moves(t_stack *stack);
void			print_moves(t_move *move);
t_move			*new_move(void);
void			moves_creator(t_stack *stackA, t_stack *stackB);
int				check_sorted(t_stack *stackA, t_stack *stackB);
int    			get_max_pos(t_stack *stackA);
void     		get_min_pos(t_node *node, t_data *data);
void    		create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data);
void    		get_median(t_stack *stack, t_data *data);
t_data 			*data_init(void);
void		    update_min(t_node *node, t_data *data);



#endif

