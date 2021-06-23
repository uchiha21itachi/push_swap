/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hundred_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:07:52 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:07:54 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_stack_sort(t_stack *stack)
{
	int		ret;
	t_node	*temp;

	temp = stack->node;
	ret = 1;
	while (temp->next != NULL)
	{
		if (temp->number < temp->next->number)
			ret = 0;
		temp = temp->next;
	}
	return (ret);
}

void	move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
{
	int	i;
	int	j;

	j = data->chunks_len - 1;
	(void)stackB;
	while (j >= 0)
	{
		get_holds(stackA, data, j);
		i = data->chunks[j]->length;
		while (i > 0)
		{
			cal_stackA_rot(stackA, stackB, data);
			adjust_stackB(stackA, stackB);
			exec("PB", stackA, stackB);
			get_holds(stackA, data, j);
			i--;
		}
		j--;
	}
}

void	cal_stackA_rot(t_stack *stackA, t_stack *stackB, t_data *data)
{
	int	m1;
	int	m2;
	int	temp;

	if (data->hold_one_pos < 1)
		return ;
	m1 = data->hold_one_pos - 1;
	m2 = (stackA->length - data->hold_two_pos) + 1;
	temp = 0;
	if (m1 < m2)
	{
		while (temp != m1)
		{
			exec("RA", stackA, stackB);
			temp++;
		}
	}
	else
	{
		while (temp != m2)
		{
			exec("RRA", stackA, stackB);
			temp++;
		}
	}
}

void	cal_stackB_rot(t_stack *stackA, t_stack *stackB, int stop_num)
{
	int	m1;
	int	m2;
	int	stop_pos;
	int	temp;

	stop_pos = get_num_pos(stackB, stop_num);
	m1 = stop_pos - 1;
	m2 = (stackB->length - stop_pos) + 1;
	temp = 0;
	if (m1 < m2)
	{
		while (temp != m1)
		{
			exec("RB", stackA, stackB);
			temp++;
		}
	}
	else
	{
		while (temp != m2)
		{
			exec("RRB", stackA, stackB);
			temp++;
		}
	}
}

void	adjust_stackB(t_stack *stackA, t_stack *stackB)
{
	t_node	*node;
	int		stop_num;
	int		num;
	int		max;

	if (stackB->length <= 1)
		return ;
	node = stackB->node;
	num = stackA->node->number;
	stop_num = num;
	max = node->number;
	while (node)
	{
		if (max < node->number)
			max = node->number;
		if (node->number < num && stop_num == num)
			stop_num = node->number;
		else if (stop_num < node->number && node->number < num)
			stop_num = node->number;
		node = node->next;
	}
	if (stop_num == num)
		stop_num = max;
	cal_stackB_rot(stackA, stackB, stop_num);
}
