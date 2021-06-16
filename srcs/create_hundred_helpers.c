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


void    cal_stackB_rot(t_stack *stackA, t_stack *stackB, int stop_num)
{
    int     m1;
    int     m2;
    int     stop_pos;
    int     temp;

    (void)stackA;
    stop_pos = get_num_pos(stackB, stop_num);
    m1 = stop_pos - 1;
    m2 = (stackB->length - stop_pos) + 1;
    temp = 0;
    if (m1 < m2)
    {
        while (temp != m1)
        {
            exec("RB", stackA, stackB);
            temp++;
        }
    }
    else
    {
        while (temp != m2)
        {
            exec("RRB", stackA, stackB);
            temp++;
        }
    }
}


void    adjust_stackB(t_stack *stackA, t_stack *stackB)
{
    t_node  *node;
    int     stop_num;
    int     num;
    int     max;

    if (stackB->length <= 1)
        return;
    node = stackB->node;
    num = stackA->node->number;
    stop_num = num;
    max = node->number;
    while (node)
    {
        if (max < node->number)
            max = node->number;
        if (node->number < num && stop_num == num)
            stop_num = node->number;
        else if (stop_num < node->number && node->number < num)
            stop_num = node->number;
        node = node->next;
    }
    if (stop_num == num)
        stop_num = max;
    cal_stackB_rot(stackA, stackB, stop_num);
}