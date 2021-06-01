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

void	temp_caller(t_stack *stackA, t_stack *stackB)
{
	int		fd;
	char	*line;
	int		ret;
	int		sort;

	fd = 0;
	sort = 0;
	print_both(stackA->node, stackB->node);
	while (((ret = get_next_line(fd, &line)) > 0) && sort == 0)
	{
		if (check_line(line) != 1)
			printf("Wrong Move Input. Please enter again\n");
		exec(line, stackA, stackB);
		free(line);
		print_both(stackA->node, stackB->node);
		sort = check_sorted(stackA, stackB);
		if (sort == 1)
			printf("Congratulations stack sorted\n Press enter to exit\n");
	}
	free(line);
	print_moves(stackA->moves);
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
	printf("args - [%s]\n", argv[1]);
	fill_stack(argv, stackA);
	temp_caller(stackA, stackB);
	free_all(stackA, stackB);
	return (0);
}
