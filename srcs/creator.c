#include "../Includes/push_swap.h"

void    create_five_helper(t_stack *stackA, t_stack *stackB)
{
    while (stackA->length > 3)
    {
        if (stackA->node->number > stackA->node->next->number)
        {
            exec("SA", stackA, stackB);
            if  (check_sorted(stackA, stackB) == 1)
                return ;
            exec("PB", stackA, stackB);        
        }
        else 
            exec("PB", stackA, stackB);        
    }
    if (stackA->node->number > stackA->node->next->number &&
        stackB->node->number < stackB->node->next->number)
            exec("SS", stackA, stackB);
    else if (stackA->node->number > stackA->node->next->number)
            exec("SA", stackA, stackB);

}

void    create_moves_five(t_stack *stackA, t_stack *stackB)
{
    int     max_pos;

    max_pos = get_max_pos(stackA);
    if (max_pos >= 3)
    {
        while (max_pos != stackA->length)
        {
            exec("RRA", stackA, stackB);
            max_pos = get_max_pos(stackA);
        }        
    }   
    while (max_pos != stackA->length)
    {
        exec("RA", stackA, stackB);
        max_pos = get_max_pos(stackA);
    }
    create_five_helper(stackA, stackB);
    if  (check_sorted(stackA, stackB) == 1)
        return ;
    while (stackB->length != 0)
    {
        exec("PA", stackA, stackB);
        if (stackA->node->number > stackA->node->next->number)
            exec("SA", stackA, stackB);
    }
}

void    create_moves_three(t_stack *stackA, t_stack *stackB)
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

void	moves_creator(t_stack *stackA, t_stack *stackB)
{

	t_node	*temp_node;

	(void)stackB;
	temp_node = stackA->node;
    get_min_max(temp_node);
    if  (check_sorted(stackA, stackB) == 1)
                return ;
	if (stackA->length <=3)
        create_moves_three(stackA, stackB);
    else if (stackA->length > 3 && stackA->length <= 5)
        create_moves_five(stackA, stackB);
    else if (stackA->length > 5 && stackA->length <= 50)
        create_moves_hundred(stackA, stackB);
}