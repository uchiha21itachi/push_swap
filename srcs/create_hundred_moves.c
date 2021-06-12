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
                    exec("SB", stackA, stackB);
                    exec("RB", stackA, stackB);
                }
                else
                {
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
    sort_stackB(stackA, stackB, req_pos, stop_num);
}

void    move_to_stackA(t_stack *stackA, t_stack *stackB, t_data *data, int j)
{
    int rot;

    if (j == (data->chunks_len - 1))
    {
        while (stackB->length != 0)
            exec("PA", stackA, stackB);
    }
    else 
    {
        rot = get_opt_rot(stackA, data, j+1);
        while (stackA->node->number != data->chunks[j + 1]->min)
        {    
            if (rot == 1)
                exec("RRA", stackA, stackB);
            else if (rot == 2)
                exec("RA", stackA, stackB);
        }
        while (stackB->length != 0)
            exec("PA", stackA, stackB);
    }

}

void    move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
{
    
    int i;
    int j;
    int ret;

    ret = -1;
    j = data->chunks_len - 1;
    (void)stackB;
    while (j >= 0)
    {
        get_holds(stackA, data, j);
        i = data->chunks[j]->length;
        while(i > 0)
        {
            cal_stackA_rot(stackA, stackB, data);
            exec("PB", stackA, stackB);
            ret = check_stack_sort(stackB);
            printf("stackB sorted? [1 - sorted] [0 - not sorted]\n ret[%d]\n", ret);
            if (ret == 0)
                sort_stackB_start(stackA, stackB);
            get_holds(stackA, data, j);
            i--;
        }
        printf("done in here\n");
        move_to_stackA(stackA, stackB, data, j);
        j--;
    }    
}

void    create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data)
{
    create_chunks(stackA, stackB, data);
    move_to_stackB(stackA, stackB, data);
}