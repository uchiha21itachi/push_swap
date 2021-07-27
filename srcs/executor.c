/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:08:14 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:08:16 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_garbage(char c, t_stack *stack)
{
	if (c != '\0')
	{
		if (!(ft_isspace_isdigit(c, 'd')))
			stack->error = 2;
	}
}

int	exec_helper(char *ins, t_stack *stackA, t_stack *stackB)
{
	if (!ft_strncmp(ins, "RRA", 3))
		reverse_rotate(stackA);
	else if (!ft_strncmp(ins, "RRB", 3))
		reverse_rotate(stackB);
	else if (!ft_strncmp(ins, "RRR", 3))
	{
		reverse_rotate(stackA);
		reverse_rotate(stackB);
	}
	else if (!ft_strncmp(ins, "RA", 3))
		rotate_ra(stackA);
	else if (!ft_strncmp(ins, "RB", 3))
		rotate_ra(stackB);
	else if (!ft_strncmp(ins, "RR", 3))
	{
		rotate_ra(stackA);
		rotate_ra(stackB);
	}
	else
	{
		ft_putstr("Wrong Move Input. Please enter again\n");
		return (0);
	}
	return (1);
}

void	exec(char *ins, t_stack *stackA, t_stack *stackB)
{
	int	i;

	i = 1;
	if (!ft_strncmp(ins, "R", 1))
		i = exec_helper(ins, stackA, stackB);
	else
	{
		if (!ft_strncmp(ins, "SA", 3))
			swap_A_B(stackA);
		else if (!ft_strncmp(ins, "SB", 3))
			swap_A_B(stackB);
		else if (!ft_strncmp(ins, "SS", 3))
		{
			swap_A_B(stackA);
			swap_A_B(stackB);
		}
		else if (!ft_strncmp(ins, "PA", 3))
			push_A_B(stackB, stackA);
		else if (!ft_strncmp(ins, "PB", 3))
			push_A_B(stackA, stackB);
		else
			i = 0;
	}
	if (i == 1)
		update_moves(stackA, ins);
}
