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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"

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

typedef struct s_chunks
{
	int		num;
	int		*members;
	int		med;
	int		max;
	int		min;
	int		length;

}				t_chunks;

typedef	struct s_data
{
	int			min;
	int			min_pos;
	int			max;
	int			max_pos;
	int			med;
	int			med_pos;
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


void	swap_A_B(t_stack *stackA);
void	push_A_B(t_stack *stackA, t_stack *stackB);
void	reverse_rotate(t_stack *stackA);
void	rotate_ra(t_stack *stackA);
void 	swap(int *arr, int i, int largest);
void	move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data);


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
void			free_data(t_data *data);
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
t_data 			*data_init(t_stack *stackA);
void		    update_min(t_node *node, t_data *data);
void    		get_holds(t_stack *stack, t_data *data, int i);
void   			print_all_min_max(t_stack *stack, t_data *data);
int 			check_stack_sort(t_stack *stack);
void   			cal_stackA_rot(t_stack *stackA, t_stack *stackB, t_data *data);
void    		cal_stackB_rot(t_stack *stackA, t_stack *stackB, int req_pos);
void   			sort_stackB(t_stack *stackA, t_stack *stackB, int req_pos, int stop_num);
void       		create_chunks(t_stack *stackA, t_stack *stackB, t_data *data);
void    		sort_number(t_data *data, int n);
void       		print_array(int *arr, int n);
int     		get_req_pos(t_data *data, int num, int len);
int			    get_opt_rot(t_stack *stackA, t_data *data, int j);
void    		adjust_stackB(t_stack *stackA, t_stack *stackBl);
int     		get_num_pos(t_stack *stack, int num);
int     		get_max_num(t_stack *stackA);
void			ft_tolower(char *str);


void			print_chunks_data(t_data *data);


#endif

