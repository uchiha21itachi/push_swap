#include "Includes/push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		printf("malloc error in stack init\n");
		return (NULL);
	}
	stack->length = 0;
	stack->node = NULL;
	return (stack);
}

t_stack		*insert_number(int num, t_stack *stack)
{
	t_node	*new;

	new = ft_lstnew(num);
	if (stack->length == 0)
		stack->node = new;
	else
		ft_lstadd_front(&stack->node, new);
	stack->length++;

	return(stack);
}

void		fill_stack(char **argv, t_stack *stack)
{
	char	*args;
	int		number;
	char	*temps;

	args = ft_strdup(argv[1]);
	temps = args;
	// printf("args - [%s]\n", temps);
	while (*temps != '\0')
	{
		number = ft_atoi(temps);
		temps = remove_space_digit(temps, 'b');
		stack = insert_number(number, stack);
		// (void)stack;
	}
	free(args);
}	
