/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:09:36 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:09:38 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//----------------------------------------------------------------
void	print_both(t_node *stackA, t_node *stackB)
{
	t_node	*tempA;
	t_node	*tempB;

	tempA = stackA;
	printf("--------------StackA--------------------\n");
	while (tempA)
	{
		if (tempA->previous != NULL && tempA->next != NULL)
			printf("[%d]\t\t<---[%d]--->\t\t[%d]\n", tempA->previous->number, tempA->number, tempA->next->number);
		else if (tempA->previous == NULL && tempA->next != NULL)
			printf("[%p]\t\t<---[%d]--->\t\t[%d]\n", tempA->previous, tempA->number, tempA->next->number);
		else if (tempA->previous != NULL && tempA->next == NULL)
			printf("[%d]\t\t<---[%d]--->\t\t[%p]\n", tempA->previous->number, tempA->number, tempA->next);
		else if (tempA->previous == NULL && tempA->next == NULL)
			printf("[%p]\t\t<---[%d]--->\t\t[%p]\n", tempA->previous, tempA->number, tempA->next);
		tempA = tempA->next;
	}

	printf("--------------StackB--------------------\n");
	tempB = stackB;
	while (tempB)
	{
		if (tempB->previous != NULL && tempB->next != NULL)
			printf("[%d]\t\t<---[%d]--->\t\t[%d]\n", tempB->previous->number, tempB->number, tempB->next->number);
		else if (tempB->previous == NULL && tempB->next != NULL)
			printf("[%p]\t\t<---[%d]--->\t\t[%d]\n", tempB->previous, tempB->number, tempB->next->number);
		else if (tempB->previous != NULL && tempB->next == NULL)
			printf("[%d]\t\t<---[%d]--->\t\t[%p]\n", tempB->previous->number, tempB->number, tempB->next);
		else if (tempB->previous == NULL && tempB->next == NULL)
			printf("[%p]\t\t<---[%d]--->\t\t[%p]\n", tempB->previous, tempB->number, tempB->next);
		tempB = tempB->next;
	}

	printf("\n-----------------XXXXXXXXXXXXXXXXXXX----------------\n\n\n");
}

//---------------------------------------------------------------------------------------


void	print_moves(t_move *move)
{
	t_move	*temp;

	temp = move;
	while (temp)
	{
		ft_tolower(temp->ins);
		printf("%s\n", temp->ins);
		temp = temp->next;
	}
}

int	check_line(char	*line)
{
	int	i;

	i = ft_strlen(line);
	if (i < 1 || i > 3)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		line[i] = ft_toupper(line[i]);
		i++;
	}
	return (1);
}

int	check_sorted(t_stack *stackA, t_stack *stackB)
{
	t_node	*temp;

	if (stackB->node != NULL)
		return (0);
	temp = stackA->node;
	while (temp->next != NULL)
	{
		if (!(temp->number < temp->next->number))
			return (0);
		temp = temp->next;
	}
	temp = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	stackA = stack_init();
	stackB = stack_init();
	fill_stack(argc, argv, stackA);
	if (stackA->error == 0 && stackA->length > 0)
		moves_creator(stackA, stackB);
	else
		ft_putstr("Error in Args \n");
	print_moves(stackA->moves);
	free_all(stackA, stackB);
	return (0);
}

/*  Change printf and error mechanism */
