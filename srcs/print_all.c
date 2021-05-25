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

void	print_stack(t_node *node)
{
	int		i;
	t_node 	*temp;

	temp = node;
	i = 0;
	while (temp)
	{
		printf("[ [%d.] - Num-[%d]\tnode-[%p]\t next-[%p]\t prev-[%p]\n",i, temp->number, temp, temp->next, temp->previous);
		i++;
		temp = temp->next;
	}
	printf("-------------------------------------------------------\n\n");
}


void	print_desc(t_stack *stack)
{
	int			next;
	int			now;
	int			prev;
	int			pn;
	int			nn;
	t_stack		*temp_stack;

	if (stack->length == 0)
	{
		printf("Stack doesnot have a list\n\n");
		return ;
	}

	if (stack->node == NULL)
	{
		printf("Stack node is null \n");
		return;
	}
	temp_stack = stack;
	next = -1;
	prev = -1;
	now = -1;
	nn = 0;
	pn = 0;
	while (temp_stack->node != NULL)
	{
		pn = 0;
		nn = 0;
		now = temp_stack->node->number;
		if (temp_stack->node->next == NULL)
			nn = 1;
		else
			next = temp_stack->node->next->number;

		if (temp_stack->node->previous == NULL)
			pn = 1;
		else
			prev = temp_stack->node->previous->number;
		
		if (pn == 1 && nn == 1)
			printf("[NULL]<-----[%d]----->[NULL]\n", now);
		else if (pn == 1 && nn != 1)
			printf("[NULL]<-----[%d]----->[%d]\n",now, next);
		else if (pn != 1 && nn == 1)
			printf("[%d]<-----[%d]----->[NULL]\n",prev ,now);
		else
			printf("[%d]<-----[%d]----->[%d]\n",prev ,now, next);

		temp_stack->node = temp_stack->node->next;
	}
}