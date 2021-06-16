#include "../Includes/push_swap.h"

void    move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
{
    
    int i;
    int j;

    j = data->chunks_len - 1;
    (void)stackB;
    while (j >= 0)
    {
        get_holds(stackA, data, j);
        i = data->chunks[j]->length;
        while(i > 0)
        {
            cal_stackA_rot(stackA, stackB, data);
            adjust_stackB(stackA, stackB);
            exec("PB", stackA, stackB);
            get_holds(stackA, data, j);
            i--;
        }
        j--;
    }    
}


void    create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data)
{
    int     max;
    int     i;

    create_chunks(stackA, stackB, data);
    move_to_stackB(stackA, stackB, data);
    max = get_max_num(stackB);
    cal_stackB_rot(stackA, stackB, max);
    i = stackB->length;
    while (i > 0)
    {
        exec("PA", stackA, stackB);
        i--;
    }
}