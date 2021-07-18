/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hundred_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:08:03 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:08:05 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_holds(t_stack *stack, t_data *data, int i)
{
	t_node	*node;
	int		pos;
	int		temp_hold;

	pos = 0;
	temp_hold = 0;
	node = stack->node;
	while (node)
	{
		pos++;
		if ((node->number <= data->chunks[i]->max) && temp_hold == 0
			&& node->number >= data->chunks[i]->min)
		{
			data->hold_one_pos = pos;
			data->hold_one = node->number;
			temp_hold = 1;
		}
		if ((node->number <= data->chunks[i]->max)
			&& node->number >= data->chunks[i]->min)
		{
			data->hold_two_pos = pos;
			data->hold_two = node->number;
		}
		node = node->next;
	}
}

int	get_max_pos(t_stack *stackA)
{
	t_node	*new;
	int		pos;
	int		i;
	int		max_number;

	pos = 1;
	i = 0;
	if (stackA->node == NULL)
		return (-1);
	new = stackA->node;
	max_number = new->number;
	while (new)
	{
		i++;
		if (max_number < new->number)
		{
			max_number = new->number;
			pos = i;
		}
		new = new->next;
	}
	return (pos);
}

int	get_max_num(t_stack *stackA)
{
	t_node	*node;
	int		max;

	node = stackA->node;
	max = node->number;
	while (node)
	{
		if (max < node->number)
			max = node->number;
		node = node->next;
	}
	return (max);
}

int	get_num_pos(t_stack *stack, int num)
{
	t_node	*node;
	int		pos;
	int		i;

	i = 0;
	pos = -1;
	node = stack->node;
	while (node)
	{
		i++;
		if (node->number == num)
			pos = i;
		node = node->next;
	}
	return (pos);
}

void	create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data)
{
	int j;
	int i;

	if (stackA->length % data->chunks_div != 0)
		data->chunks_len++;
	create_chunks(stackA, stackB, data);
	j = data->chunks_len - 1;
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
		move_to_stackB(stackA, stackB, data, j);
		j--;
	}
}
