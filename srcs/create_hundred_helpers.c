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

// void    cal_stackB_rot(t_stack *stackA, t_stack *stackB, int req_pos)
// {
//     int m1;
//     int m2;
//     int temp;

//     temp = 0;
//     m1 = req_pos - 1;
//     m2 = (stackB->length - req_pos) + 1;
//     if (m1 < m2)
//     {
//         while (temp != m1)
//         {
//             exec("RRB", stackA, stackB);
//             temp++;
//         }
//     }
//     else
//     {
//         while (temp != m2)
//         {
//             exec("RB", stackA, stackB);
//             temp++;
//         }
//     }
// }

void    cal_stackB_rot(t_stack *stackA, t_stack *stackB, int stop_num)
{
    int     m1;
    int     m2;
    int     stop_pos;
    int     temp;

    (void)stackA;
    stop_pos = get_num_pos(stackB, stop_num);
    printf("stop_num is [%d] pos in stack [%d] \n", stop_num, stop_pos);

    m1 = stop_pos - 1;
    m2 = (stackB->length - stop_pos) + 1;
    printf("m1 [%d] m2 [%d] \n", m1, m2);

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


void    adjust_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
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
    // printf("Number to work on [%d]\n", stackA->node->number);
    // printf("Number to stop stackB on [%d]\n", stop_num);
    cal_stackB_rot(stackA, stackB, stop_num);
    (void)data;
}