/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:08:24 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:08:27 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_tolower(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
}

void	swap_A_B(t_stack *stackA)
{
	t_node	*newA;

	if (stackA->length < 2)
		return ;
	newA = stackA->node->next;
	if (stackA->length == 2)
	{
		newA->next = stackA->node;
		stackA->node->next = NULL;
		newA->previous = NULL;
		stackA->node->previous = newA;
		stackA->node = newA;
		return ;
	}
	stackA->node->next = newA->next;
	newA->next->previous = stackA->node;
	newA->next = newA->previous;
	newA->previous = NULL;
	stackA->node->previous = newA;
	stackA->node = newA;
}

void	push_A_B(t_stack *stackA, t_stack *stackB)
{
	t_node	*new;

	if (stackA->length < 1)
		return ;
	if (stackA->length < 2)
	{
		new = stackA->node;
		ft_lstadd_front(stackB, new);
		stackA->node = NULL;
	}
	else
	{
		new = stackA->node->next;
		new->previous = NULL;
		stackA->node->next = NULL;
		ft_lstadd_front(stackB, stackA->node);
		stackA->node = new;
	}
	stackA->length--;
	stackB->length++;
}

void	rotate_ra(t_stack *stackA)
{
	t_node	*newA;

	if (stackA->length < 2)
		return ;
	newA = stackA->node->next;
	stackA->node->previous = ft_lstlast(newA);
	ft_lstlast(newA)->next = newA->previous;
	stackA->node->next = NULL;
	newA->previous = NULL;
	stackA->node = newA;
}

void	reverse_rotate(t_stack *stackA)
{
	t_node	*newA;

	if (stackA->length < 2)
		return ;
	newA = ft_lstlast(stackA->node);
	newA->previous->next = NULL;
	newA->previous = NULL;
	ft_lstadd_front(stackA, newA);
}
