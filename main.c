#include "Includes/push_swap.h"


void	free_stack(t_stack *stack)
{
	t_node 	*new;

	if (stack->node == NULL)
		return ;
	while (stack->node->next != NULL)
	{
		new = ft_lstlast(stack->node);
		new->previous->next = NULL;
		free(new);
	}
	if (stack->node != NULL)
		free(stack->node);
}

void	free_all(t_stack *stackA, t_stack *stackB)
{
	free_stack(stackA);
	free_stack(stackB);
	free(stackA);	
	free(stackB);		
}

void	temp_caller(t_stack *stackA, t_stack *stackB)
{

	print_both(stackA->node, stackB->node);
	exec("PB", stackA, stackB);
	print_both(stackA->node, stackB->node);
	exec("PB", stackA, stackB);
	print_both(stackA->node, stackB->node);
	exec("PB", stackA, stackB);
	print_both(stackA->node, stackB->node);
	exec("RA", stackA, stackB);
	print_both(stackA->node, stackB->node);
	exec("RB", stackA, stackB);
	print_both(stackA->node, stackB->node);

}

int		main(int argc, char **argv)
{
	t_stack		*stackA;
	t_stack		*stackB;

	if (argc != 2)
	{
		printf("Error - Please enter ARG as arguments\n");
		return (0);
	}
	(void)stackB;
	stackA = stack_init();
	stackB = stack_init();
	printf("args - [%s]\n", argv[1]);
	fill_stack(argv, stackA);
	temp_caller(stackA, stackB);
	free_all(stackA, stackB);
	return (0);
}
