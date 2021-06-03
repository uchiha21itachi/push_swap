#include "../Includes/push_swap.h"

void    get_min_max(t_node  *node)
{
    int		min;
	int		max;

    min = node->number;
	max = node->number;
	while (node)
	{
		if (min > node->number)
			min = node->number;
		if (max < node->number)
			max = node->number;
		node = node->next;
	}
	printf("min - [%d] max [%d]\n", min, max);
}


void	moves_creator(t_stack *stackA, t_stack *stackB)
{

	t_node	*temp_node;

	(void)stackB;
	temp_node = stackA->node;
    get_min_max(temp_node);
    if  (check_sorted(stackA, stackB) == 1)
                return ;
	if (stackA->length <=3)
	{
        if (stackA->node->number > stackA->node->next->number)
        {
            exec("SA", stackA, stackB);
            if  (check_sorted(stackA, stackB) == 1)
                return ;
            exec("RRA", stackA, stackB);
            if (stackA->node->number > stackA->node->next->number)
                exec("SA", stackA, stackB);
        }
        else
        {
            if(stackA->node->number < ft_lstlast(stackA->node)->number)
            {
                exec("RA", stackA, stackB);
                exec("SA", stackA, stackB);
                exec("RRA", stackA, stackB);
            }
            else
                exec("RRA", stackA, stackB);
        }
	}
}