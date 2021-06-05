#include "../Includes/push_swap.h"

void    print_all_min_max(t_stack *stack, t_data *data)
{
    t_node  *temp;
    int pos;

    pos = 0;
    temp = stack->node;
    printf("\n\n");
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
    printf("\n\n");

}


void   cal_optimal_rot(t_stack *stackA, t_stack *stackB, t_data *data)
{
    int     m1;
    int     m2;
    int     temp;

    (void)stackB;
    m1 = data->hold_one - 1;
    m2 = (stackA->length - data->hold_two) + 1;
    temp = 0;
    printf("moves to make hold one at top [%d]\n", m1);
    printf("moves to make hold two at top [%d]\n", m2);
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
    exec("PB", stackA, stackB);
    get_holds(stackA, data, 2);
    //add a cond if m1==m2 then take priority to m1 if m1<m2 or vice versa
}

void    move_to_stackB(t_stack *stackA, t_stack *stackB, t_data *data)
{
    // int i;
    int chunks;
    chunks = (stackA->length / 20) + 1;

    // i = 0;
    if (chunks == 1)
    {
        while(stackA->length != 0)
        {
            printf("before - Hold_one is in  pos - [%d]\n", data->hold_one);
            printf("before - Hold_two is in  pos - [%d]\n", data->hold_two);
            cal_optimal_rot(stackA, stackB, data);
            printf("Hold_one is in  pos - [%d]\n", data->hold_one);
            printf("Hold_two is in  pos - [%d]\n", data->hold_two);
        }
    }    
    
}

void    create_moves_hundred(t_stack *stackA, t_stack *stackB, t_data *data)
{

    get_median(stackA, data);
    print_all_min_max(stackA, data);
    printf("Length of stackA- [%d]\n",stackA->length);
    get_holds(stackA, data, 2);
    move_to_stackB(stackA, stackB, data);

}