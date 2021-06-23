/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_crud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:08:54 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:08:56 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lstnew(int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		return (NULL);
	new->number = number;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack *stack, t_node *new)
{
	if (new == NULL)
		return ;
	if (stack->node != NULL)
	{
		new->next = stack->node;
		stack->node->previous = new;
		stack->node = new;
	}
	else
		stack->node = new;
}

void	ft_lstadd_back(t_stack *stack, t_node *new)
{
	t_node	*ls;

	if (new == NULL)
		return ;
	if (stack->node)
		ls = stack->node;
	else
	{
		stack->node = new;
		return ;
	}
	while (ls->next != NULL)
		ls = ls->next;
	new->previous = ls;
	ls->next = new;
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*p;

	p = lst;
	if (lst == NULL)
		return (NULL);
	while (p->next != NULL)
		p = p->next;
	return (p);
}
