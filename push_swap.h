/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:10:29 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:10:31 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"	

typedef struct s_move
{
	char			*ins;
	int				mov_num;
	struct s_move	*next;
}				t_move;

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

typedef struct s_stack
{
	struct s_node	*node;
	struct s_move	*moves;
	int				length;
	int				error;
}				t_stack;

typedef struct s_chunks
{
	int		num;
	int		*members;
	int		med;
	int		max;
	int		min;
	int		length;

}				t_chunks;

typedef struct s_data
{
	int			hold_one;
	int			hold_one_pos;
	int			hold_two;
	int			hold_two_pos;
	int			chunks_div;
	int			chunks_len;
	int			stack_len;
	int			*og_pos;
	int			*og_stack;
	int			*req_pos;
	t_chunks	**chunks;
}				t_data;

//utils.c
int		check_sorted(t_stack *stackA, t_stack *stackB);
void	ft_putstr(char *str);
t_stack	*stack_init(void);
void	ft_tolower(char *str);

//stack_init.c
void	fill_stack(int argc, char **argv, t_stack *stack);
t_data	*data_init(t_stack *stackA);

//libft_utils.c
int		ft_toupper(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*remove_space_digit(char *line, char c);
int		ft_isspace_isdigit(char c, char d);

//free.c
void	free_data(t_data *data);
void	free_all(t_stack *stackA, t_stack *stackB);

//list_crud.c
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_stack *stack, t_node *new);
void	ft_lstadd_front(t_stack *stack, t_node *new);
t_node	*ft_lstnew(int number);

//moves_creator.c
void	moves_creator(t_stack *stackA, t_stack *stackB);

//moves_init.c
t_move	*new_move(void);
void	add_move_back(t_stack *stackA, t_move *move);
void	update_moves(t_stack *stackA, char *ins);
void	swap(int *arr, int i, int largest);

//executor.c
void	exec(char *ins, t_stack *stackA, t_stack *stackB);

//executor_helper.c
void	reverse_rotate(t_stack *stackA);
void	rotate_ra(t_stack *stackA);
void	push_A_B(t_stack *stackA, t_stack *stackB);
void	swap_A_B(t_stack *stackA);

//create_hundred_moves
void	create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data);
int		get_num_pos(t_stack *stack, int num);
int		get_max_num(t_stack *stackA);
int		get_max_pos(t_stack *stackA);
void	get_holds(t_stack *stack, t_data *data, int i);

//create_hundred_helperes
void	cal_stackB_rot(t_stack *stackA, t_stack *stackB, int stop_num);
void	cal_stackA_rot(t_stack *stackA, t_stack *stackB, t_data *data);
void	adjust_stackB(t_stack *stackA, t_stack *stackB);
void	move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data, int j);
void	move_to_stackA(t_stack *stackA, t_stack *stackB, t_data *data, int n);

//partition.c
void	create_chunks(t_stack *stackA, t_stack *stackB, t_data *d);

#endif
