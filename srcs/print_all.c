#include "../Includes/push_swap.h"

void	print_numbers(t_node *list, char x)
{
	t_node	*temp;

	temp =  list;
    if (x == 'A')
    	printf("---------------------StackA ------------------\n");
	else if (x == 'B')
    	printf("---------------------StackB ------------------\n");
    else
    	printf("---------------------TEMP Stack ------------------\n");

	if (list == NULL)
	{
		printf("empty list....\n");
		return ;
	}
    while (temp)
	{
		printf("[%d]\n", temp->number);
		temp = temp->next;
	}
}

void	print_stack(t_stack *stack)
{
	int		i;
	t_node 	*temp;

	temp = stack->node;
	i = 0;
	printf("stack length -> [%d]\n", stack->length);
	while (temp)
	{
		printf("[ [%d.] - Num-[%d]\tnode-[%p]\t next-[%p]\t prev-[%p]\n",i, temp->number, temp, temp->next, temp->previous);
		i++;
		temp = temp->next;
	}
	printf("-------------------------------------------------------\n\n");
}

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

void	print_moves(t_move *move)
{
	t_move	*temp;

	temp = move;
	printf("Showing all moves\n\n");
	while (temp)
	{
		printf("[%d] - [%s]\n", temp->mov_num, temp->ins);
		temp = temp->next;
	}
	printf("-------------------------\n\n\n");
}