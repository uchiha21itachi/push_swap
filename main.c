#include "Includes/push_swap.h"


t_node	*list_init(void)
{
	t_node	*list;

	list = malloc(sizeof (t_node *));
	if (list == NULL)
	{
		printf("malloc error in list init\n");
		return (NULL);
	}	
	return (list);
}

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
	return ;
}

void	check_args(char **argv, t_node *stackA)
{
	char	*args;
	int		number;
	int		counter;
	t_node	*new;

	args = ft_strdup(argv[1]);
	//Free args and check args pending

	counter = 0;
	while (*args != '\0')
	{
		number = ft_atoi(args);
		args = remove_space_digit(args, 'b');		
		if (counter == 0)
		{
			stackA->number = number;
			stackA->next = NULL;
		}
		else
		{
			new = ft_lstnew(number);
			ft_lstadd_back(&stackA, new);
		}
		counter++;
		args++;
	}
	printf("number of total args - [%d]\n\n", counter);
	
	stack_iterator(stackA);
}	

int		main(int argc, char **argv)
{
	t_node	*stackA;
	t_node	*stackB;

	if (argc < 2)
	{
		printf("Error - Please enter ARG as arguments\n");
		return (0);
	}
	stackA = list_init();
	stackB = list_init();
	check_args(argv, stackA);
	printf("Successfully exited check args ....\n");
	
	// (void)stackA;
	(void)stackB;
	return (0);
}
