#include "Includes/push_swap.h"


void	free_stack(t_stack *stack)
{
	t_node 	*new;

	while (stack->node->next != NULL)
	{
		new = ft_lstlast(stack->node);
		new->previous->next = NULL;
		free(new);
	}
	if (stack->node != NULL)
		free(stack->node);
}


int		main(int argc, char **argv)
{
	t_stack		*stackA;
	t_stack		*stackB;

	(void)argv;
	if (argc != 2)
	{
		printf("Error - Please enter ARG as arguments\n");
		return (0);
	}
	(void)stackA;
	(void)stackB;

	stackA = stack_init();
	stackB = stack_init();
	fill_stack(argv, stackA);
	// printf("length stack A - [%d]\n", stackA->length);
	// printf("length stack B - [%d]\n", stackB->length);
	checker("SA", stackA, stackB);
	free_stack(stackA);
	free(stackA);	
	free(stackB);		
	return (0);
}
