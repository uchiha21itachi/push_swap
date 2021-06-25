#include "../push_swap.h"

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
	stack->error = 0;
	stack->node = NULL;
	stack->moves = NULL;
	return (stack);
}


void	ft_putstr(char *str)
{
	int		len;
	int		i;
	int		ret;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ret = write(1, &str[i], 1);
		i++;
	}
	(void)ret;
}