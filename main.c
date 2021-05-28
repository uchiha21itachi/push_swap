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
	printf("args - [%s]\n", argv[1]);

	// fill_stack(argv, stackA);
	// print_desc(stackA->node);
	// checker("SA", stackA, stackB);
	// print_desc(stackA->node);

	free_stack(stackA);
	printf("looks good\n");
	free(stackA);	
	free(stackB);		
	return (0);
}
