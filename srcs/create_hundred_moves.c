#include "../Includes/push_swap.h"

void   sort_stackB(t_stack *stackA, t_stack *stackB, int req_pos, int stop_num)
{
    if (req_pos == 2)
        exec("SB", stackA, stackB);
    else if (req_pos == stackB->length)
        exec("RB", stackA, stackB);
    else if (req_pos > 2 && req_pos != stackB->length)
    {
            while (stackB->node->next->number != stop_num)
            {
                if(req_pos <= stackB->length / 2)
                {
                    // printf("case 1 sb rb\n");
                    exec("SB", stackA, stackB);
                    exec("RB", stackA, stackB);
                }
                else
                {
                    // printf("case 2 rrb  sb\n");
                    exec("RRB", stackA, stackB);
                    exec("SB", stackA, stackB);
                }
            }
        cal_stackB_rot(stackA, stackB, req_pos);
    }
}


void    sort_stackB_start(t_stack *stackA, t_stack *stackB)
{
    int     num;
    int     stop_num;
    t_node  *temp;
    int     pos;
    int     req_pos;

    num = stackB->node->number;
    temp = stackB->node;
    pos = 0;
    req_pos = 0;
    stop_num = 0;
    while (temp)
    {
        pos++;
        if(temp->number > num)
        {
            req_pos = pos;
            if(temp->next != NULL)
                stop_num = temp->next->number;
        }
        temp = temp->next;
    }
    // printf("required pos [%d] stackB length [%d] stop_num [%d]\n",req_pos, stackB->length, stop_num);
    sort_stackB(stackA, stackB, req_pos, stop_num);
}

void    move_to_stackA(t_stack *stackA, t_stack *stackB, t_data *data)
{
    while (stackB->length != 0)
        exec("PA", stackA, stackB);
    (void)data;
}

void    move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
{
    int i;
    int ret;
    int chunks;

    chunks = stackA->length / 20;
    if (stackA->length % 20  != 0)
        chunks++;
    ret = -1;
    get_holds(stackA, data, 2);
    if (chunks == 1)
    {
        i = stackA->length / 2;
        while(stackA->length != i)
        {
            cal_stackA_rot(stackA, stackB, data);
            exec("PB", stackA, stackB);
            ret = check_stack_sort(stackB);
            printf("stackB sorted? [1 - sorted] [0 - not sorted]\n ret[%d]\n", ret);
            if (ret == 0)
                sort_stackB_start(stackA, stackB);
            get_holds(stackA, data, 2);
        }
        printf("done in here\n");
        move_to_stackA(stackA, stackB, data);
    }    
}

void    create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data)
{
    create_chunks(stackA, stackB, data);
    // get_median(stackA, data);
    (void)stackB;
    // move_to_stackB(stackA, stackB, data);
    // print_all_min_max(stackA, data);
    // free_og_data(stackA, data);
}