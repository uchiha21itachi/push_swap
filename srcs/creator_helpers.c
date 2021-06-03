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


int     get_max_pos(t_stack *stackA)
{
    t_node  *new;
    int     pos;
    int     i;
    int     max_number;

    pos = 1;
    i = 0;
    if (stackA->node == NULL)
        return (-1);

    printf("Length of stack in question - [%d]\n", stackA->length);
    new = stackA->node;
    max_number = new->number;
    while (new)
    {
        i++;
        if (max_number < new->number)
        {
            max_number = new->number;
            pos = i; 
        } 
        new = new->next;
    }
    printf("max_number - [%d] position in stack - [%d]\n", max_number, pos);
    return (pos);
}