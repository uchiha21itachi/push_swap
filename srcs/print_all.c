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

void	print_desc(t_node *node)
{
	t_node	*temp;

	temp = node;
	while (temp)
	{
		if (temp->previous != NULL && temp->next != NULL)
			printf("[%d]\t\t<---[%d]--->\t\t[%d]\n", temp->previous->number, temp->number, temp->next->number);
		else if (temp->previous == NULL && temp->next != NULL)
			printf("[%p]\t\t<---[%d]--->\t\t[%d]\n", temp->previous, temp->number, temp->next->number);
		else if (temp->previous != NULL && temp->next == NULL)
			printf("[%d]\t\t<---[%d]--->\t\t[%p]\n", temp->previous->number, temp->number, temp->next);
		else if (temp->previous == NULL && temp->next == NULL)
			printf("[%p]\t\t<---[%d]--->\t\t[%p]\n", temp->previous, temp->number, temp->next);
		temp = temp->next;
	}
}
