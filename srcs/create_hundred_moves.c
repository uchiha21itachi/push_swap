#include "../Includes/push_swap.h"

void    print_all_min_max(t_stack *stack, t_data *data)
{
    t_node  *temp;
    int pos;

    pos = 0;
    temp = stack->node;
    while(temp)
    {
        pos++;
        if (temp->number <= data->med)
        {
            printf("less - [%d] - pos - [%d]\n", temp->number, pos);
        }
        temp = temp->next;
    }

    temp = stack->node;
    pos = 0;
    while(temp)
    {
        pos++;
        if (temp->number > data->med)
        {
            printf("greater - [%d] - pos - [%d]\n", temp->number, pos);
        }
        temp = temp->next;
    }

}

int     check_stop_loop(t_stack *stack, t_data *data)
{
    int     i;
    t_node  *node;

    i = 0;
    node = stack->node;
    while (node)
    {
        if (node->number <= data->med)
            return (1);
        node = node->next;
    }
    return (0);
}

void    move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
{

    (void)stackB;
    get_median(stackA, data);
    print_all_min_max(stackA, data);
    
    while (data->min <= data->med)
    {
        while (data->min_pos != 1)
        {
            if (data->min_pos > (stackA->length / 2))
                exec("RRA", stackA, stackB);
            else
                exec("RA", stackA, stackB);
            get_min_pos(stackA->node, data);
        }
        exec("PB", stackA, stackB);
        update_min(stackA->node, data);
        printf("NEW -> min [%d] min pos [%d]\n",data->min, data->min_pos);
    }
    while (data->min_pos != 1)
    {
        if (data->min_pos > (stackA->length / 2))
            exec("RRA", stackA, stackB);
        else
            exec("RA", stackA, stackB);
        get_min_pos(stackA->node, data);

    }
    while (stackB->length != 0)
        exec("PA", stackA, stackB);

     
}

void    create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data)
{
    move_to_stackB(stackA, stackB, data);
}