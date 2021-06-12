#include "../Includes/push_swap.h"

int check_stack_sort(t_stack *stack)
{
    int     ret;
    t_node  *temp;

    temp = stack->node;
    ret = 1;
    while (temp->next != NULL)
    {
        if (temp->number < temp->next->number)
            ret = 0;
        temp = temp->next;
    }
    return (ret);
}

int     get_opt_rot(t_stack *stackA, t_data *data, int j)
{
    t_node *node;
    int     i;
    int     pos1;

    printf("j[%d] j chunk max[%d] in getoptrot\n ", j, data->chunks[j]->min);
    i = 0;
    pos1 = 0;
    node = stackA->node;
    while (node)
    {
        if (node->number == data->chunks[j]->min)
            pos1 = i + 1;
        i++;
        node = node->next; 
    }
    printf("pos1[%d]\n", pos1);
    printf("moves 1 [%d]\n", pos1 - 1);
    printf("moves 2 [%d]\n", (stackA->length - pos1) + 1);
    if ((pos1 -1) >= (stackA->length - pos1) + 1)
        return (1);
    else if ((pos1 -1) < (stackA->length - pos1) + 1)
        return (2);
    return (-1);
}

void   cal_stackA_rot(t_stack *stackA, t_stack *stackB, t_data *data)
{
    int     m1;
    int     m2;
    int     temp;

    (void)stackB;
    m1 = data->hold_one_pos - 1;
    m2 = (stackA->length - data->hold_two_pos) + 1;
    temp = 0;
    if (m1 < m2)
    {
        while(temp != m1)
        {
            exec("RA", stackA, stackB);
            temp++;      
        }
    }
    else
    {
        while(temp != m2)
        {
            exec("RRA", stackA, stackB);
            temp++;      
        }
    }
}

void    cal_stackB_rot(t_stack *stackA, t_stack *stackB, int req_pos)
{
    int m1;
    int m2;
    int temp;

    temp = 0;
    m1 = req_pos - 1;
    m2 = (stackB->length - req_pos) + 1;
    if (m1 < m2)
    {
        while (temp != m1)
        {
            exec("RRB", stackA, stackB);
            temp++;
        }
    }
    else
    {
        while (temp != m2)
        {
            exec("RB", stackA, stackB);
            temp++;
        }
    }
}
