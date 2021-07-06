/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:09:10 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:09:12 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_move	*new_move(void)
{
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (move == 0)
		return (NULL);
	move->mov_num = -1;
	move->next = NULL;
	move->ins = NULL;
	return (move);
}

void	add_move_back(t_stack *stackA, t_move *move)
{
	t_move	*new;

	new = stackA->moves;
	while (new->next != NULL)
		new = new->next;
	move->mov_num = new->mov_num + 1;
	new->next = move;
}

void	update_moves(t_stack *stackA, char *ins)
{
	t_move	*move;

	move = new_move();
	if (move == NULL)
		return ;
	move->ins = ft_strdup(ins);
	if (stackA->moves == NULL)
	{
		move->mov_num = 1;
		stackA->moves = move;
		return ;
	}
	add_move_back(stackA, move);
}

void	swap(int *arr, int i, int largest)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = temp;
}
