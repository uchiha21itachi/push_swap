#include "Includes/push_swap.h"

void	stack_iterator(t_node *stack)
{
	int		i;
	t_node	*new;

	i = 0;
	if (!stack)
	{
		printf("Problem in stack returning from function now\n");
		return;
	}
	new = stack;
	while (new != NULL)
	{
		printf("stack number at [%d] is = [%d]\n", i, new->number);
		new = new->next;
		i++;
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


void	free_stack(t_stack *stack)
{
	t_node 	*new;
	// t_node 	*temp;

	new = ft_lstlast(stack->node);
	
	// while (new->previous != NULL)
	// {
		print_stack(new);
		print_stack(stack->node);
		


		// new->previous->next = NULL;		
		// temp = new;
		// if (new->previous != NULL)
			// new = new->previous;		
		// temp->previous = NULL;
		// free(temp);
	// }
}


int		main(int argc, char **argv)
{
	t_stack		*stackA;
	// t_stack		*stackB;

	(void)argv;
	if (argc != 2)
	{
		printf("Error - Please enter ARG as arguments\n");
		return (0);
	}
	stackA = stack_init();
	fill_stack(argv, stackA);
	// print_stack(stackA->node);
	free_stack(stackA);
	free(stackA);

	return (0);
}
