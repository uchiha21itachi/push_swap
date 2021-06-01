#include "../Includes/push_swap.h"


void	free_moves(t_stack *stack)
{
		t_move	*new;

		if (stack->moves == NULL)
		return ;
		printf("inside free moves-\n");
		new = stack->moves->next;
		while (new != NULL)
		{
			stack->moves->next = NULL;
			free(stack->moves->ins);
			free(stack->moves);
			stack->moves = new;
			new = stack->moves->next;
		}
		free(stack->moves->ins);
		free(stack->moves);
}

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
	free_moves(stack);
}

void	free_all(t_stack *stackA, t_stack *stackB)
{
	free_stack(stackA);
	free_stack(stackB);
	free(stackA);	
	free(stackB);		
}