#include "../Includes/push_swap.h"

int     get_max_num(t_stack *stackA)
{
    t_node  *node;
    int     max;

    node = stackA->node;
    max = node->number;
    while (node)
    {
        if (max < node->number)
            max = node->number;
        node = node->next;
    }
    return (max);
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
    return (pos);
}

int     get_num_pos(t_stack *stack, int num)
{
    t_node *node;
    int     pos;
    int     i;

    i = 0;
    pos = -1;
    node = stack->node;
    while (node)
    {
        i++;
        if (node->number == num)
            pos = i;
        node = node->next;
    }
    return (pos);
}


void    get_holds(t_stack *stack, t_data *data, int i)
{
    t_node *node;
    int     pos;
    int     temp_hold;

    pos = 0;
    temp_hold = 0;

    node = stack->node;
    while (node)
    {
        pos++;
        if ((node->number <= data->chunks[i]->max) && temp_hold == 0
            && node->number >= data->chunks[i]->min)
        {
            data->hold_one_pos = pos;
            data->hold_one = node->number;
            temp_hold = 1;
        }
        node = node->next;
    }
    pos = stack->length;
    temp_hold = 0;
    node = ft_lstlast(stack->node);
    while (node)
    {
        if ((node->number <= data->chunks[i]->max) && temp_hold == 0
            && node->number >= data->chunks[i]->min)
        {
            data->hold_two_pos = pos;
            data->hold_two = node->number;
            temp_hold = 1;
        }
        node = node->previous;
        pos--;
    }
}

