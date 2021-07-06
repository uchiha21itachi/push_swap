/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:09:03 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:09:04 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	empty_stack(t_stack *stackA, t_stack *stackB)
{
	if (check_sorted(stackA, stackB) == 1)
		return ;
	while (stackB->length != 0)
	{
		exec("PA", stackA, stackB);
		if (stackA->node->number > stackA->node->next->number)
			exec("SA", stackA, stackB);
	}
}

void	create_five_helper(t_stack *stackA, t_stack *stackB)
{
	while (stackA->length > 3)
	{
		if (stackA->node->number > stackA->node->next->number)
		{
			exec("SA", stackA, stackB);
			if (check_sorted(stackA, stackB) == 1)
				return ;
		}
		exec("PB", stackA, stackB);
	}
	if (stackA->node->number > stackA->node->next->number
		&& stackB->length > 1)
	{
		if (stackB->node->number < stackB->node->next->number)
			exec("SS", stackA, stackB);
		else
			exec("SA", stackA, stackB);
	}
	else if (stackA->node->number > stackA->node->next->number)
		exec("SA", stackA, stackB);
}

void	create_moves_five(t_stack *stackA, t_stack *stackB)
{
	int	max_pos;

	max_pos = get_max_pos(stackA);
	if (max_pos >= 3)
	{
		while (max_pos != stackA->length)
		{
			exec("RRA", stackA, stackB);
			max_pos = get_max_pos(stackA);
		}
	}
	else
	{
		while (max_pos != stackA->length)
		{
			exec("RA", stackA, stackB);
			max_pos = get_max_pos(stackA);
		}
	}
	create_five_helper(stackA, stackB);
	empty_stack(stackA, stackB);
}

void	create_moves_three(t_stack *stackA, t_stack *stackB)
{
	if (stackA->node->number > stackA->node->next->number)
	{
		exec("SA", stackA, stackB);
		if (check_sorted(stackA, stackB) == 1)
			return ;
		exec("RRA", stackA, stackB);
		if (stackA->node->number > stackA->node->next->number)
			exec("SA", stackA, stackB);
	}
	else
	{
		if (stackA->node->number < ft_lstlast(stackA->node)->number)
		{
			exec("RA", stackA, stackB);
			exec("SA", stackA, stackB);
			exec("RRA", stackA, stackB);
		}
		else
			exec("RRA", stackA, stackB);
	}
}

void	moves_creator(t_stack *stackA, t_stack *stackB)
{
	t_data	*sort_data;

	if (check_sorted(stackA, stackB) == 1)
		return ;
	sort_data = data_init(stackA);
	if (stackA->length <= 3)
		create_moves_three(stackA, stackB);
	else if (stackA->length > 3 && stackA->length <= 5)
		create_moves_five(stackA, stackB);
	else if (stackA->length > 5 && stackA->length <= 100)
	{
		sort_data->chunks_div = 20;
		sort_data->chunks_len = stackA->length / sort_data->chunks_div;
		create_moves_hundred(stackA, stackB, sort_data);
	}
	else if (stackA->length > 100 && stackA->length <= 500)
	{
		sort_data->chunks_div = 50;
		sort_data->chunks_len = stackA->length / sort_data->chunks_div;
		create_moves_hundred(stackA, stackB, sort_data);
	}
	if (stackA->length > 5 && stackA->length <= 500)
		free_data(sort_data);
	else
		free(sort_data);
}
