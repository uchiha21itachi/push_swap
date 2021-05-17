#include "Includes/push_swap.h"


t_list	*list_init(void)
{
	t_list	*list;

	list = malloc(sizeof (t_list *));
	if (list == NULL)
	{
		printf("malloc error in list init\n");
		return (NULL);
	}	
	return (list);
}

void	stack_iterator(t_list *stack)
{
	int		i;
	t_list	*new;

	i = 0;
	if (!stack)
	{
		printf("Problem in stack returning from function now\n");
		return;
	}
	new = stack;
	while (new != NULL)
	{
		printf("stack content at [%d] is = [%d]\n", i, new->content);
		new = new->next;
		i++;
	}
	return ;
}

void	check_args(char **argv, t_list *stackA)
{
	char	*args;
	int		number;
	int		counter;
	t_list	*new;

	args = ft_strdup(argv[1]);
	//Free args and check args pending

	counter = 0;
	while (*args != '\0')
	{
		number = ft_atoi(args);
		args = remove_space_digit(args, 'b');		
		if (counter == 0)
		{
			stackA->content = number;
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
	printf("Number of total args - [%d]\n\n", counter);
	
	stack_iterator(stackA);
}	

int		main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;

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
