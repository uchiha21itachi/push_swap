#include "../Includes/push_swap.h"

int		check_line(char	*line)
{
	int		i;

	i  = ft_strlen(line);
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

int		check_sorted(t_stack *stackA, t_stack *stackB)
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

int		main(int argc, char **argv)
{
	t_stack		*stackA;
	t_stack		*stackB;
	if (argc != 2)
	{
		printf("Error - Please enter ARG as arguments\n");
		return (0);
	}
	stackA = stack_init();
	stackB = stack_init();
	fill_stack(argv, stackA);
	moves_creator(stackA, stackB);
	print_moves(stackA->moves);
	free_all(stackA, stackB);
	return (0);
}




/*
	Need to check duplicates in arg
	Change printf and error mechanism
*/