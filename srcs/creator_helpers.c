#include "../Includes/push_swap.h"

void    get_median(t_stack *stack, t_data *data)
{
    t_node  *node;
    int     i;

    node = stack->node;
    i = 0;
    data->min = node->number;
	data->max = node->number;
	while (node)
	{
		if (data->min > node->number)
			data->min = node->number;
		if (data->max < node->number)
			data->max = node->number;
		node = node->next;
	}
    data->med = (data->max + data->min) / 2;
    node = stack->node;
    while (node)
    {
        i++;
        if (node->number == data->med)
            data->med_pos = i;
        if (node->number == data->max)
            data->max_pos = i;
        if (node->number == data->min)
            data->min_pos = i;
        node = node->next;
    }
    printf("max [%d] min [%d] med_num [%d] med_pos [%d]\n", data->max, data->min, data->med, data->med_pos);
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

void     get_min_pos(t_node *node, t_data *data)
{
    t_node  *temp;
    int     i;

    i = 0;
    temp = node;
    while (temp)
    {
        i++;
        if (temp->number == data->min)
            data->min_pos = i;
        temp = temp->next;
    }
}

void    update_min(t_node *node, t_data *data)
{
    t_node  *temp;
    int     i;

    i = 0;
    temp = node;
    data->min = temp->number;
    while (temp)
    {
        i++;
        if (data->min > temp->number)
            data->min = temp->number;
        temp = temp->next;
    }
    get_min_pos(node, data);
}


void    get_holds(t_stack *stack, t_data *data, int i)
{
    t_node *node;
    int     pos;
    int     temp_hold;

    pos = 0;
    temp_hold = 0;
    if (i == 2 || i == 0)
    {
        node = stack->node;
        while (node)
        {
            pos++;
            if ((node->number <= data->med) && temp_hold == 0)
            {
                data->hold_one = pos;
                temp_hold = 1;
            }
            node = node->next;
        }
    }
    pos = stack->length;
    temp_hold = 0;
    if (i == 2 || i == 1)
    {
        node = ft_lstlast(stack->node);
        while (node)
        {
            if ((node->number <= data->med) && temp_hold == 0)
            {
                data->hold_two = pos;
                temp_hold = 1;
            }
            node = node->previous;
            pos--;
        }
    }

}

