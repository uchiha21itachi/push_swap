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

void	move_to_stackA(t_stack *stackA, t_stack *stackB, t_data *data, int num_pos)
{
	int	max;
	int k;

	if (num_pos >= 0)
	{
		data->hold_one_pos = num_pos;
		data->hold_two_pos = num_pos;
		cal_stackA_rot(stackA, stackB, data);
	}
	max = get_max_num(stackB);
	cal_stackB_rot(stackA, stackB, max);
	k = stackB->length;
	while (k > 0)
	{
		exec("PA", stackA, stackB);
		k--;
	}
}

void	move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
{
	int	i;
	int	j;
	int num_pos;

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
		num_pos = -1;
		if (data->chunks_len > 1)
		{
			if (j != data->chunks_len - 1)
				num_pos = get_num_pos(stackA, data->chunks[j + 1]->min);
			else
				num_pos = get_num_pos(stackA, stackA->node->number);
		}
		move_to_stackA(stackA, stackB, data, num_pos);
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
