#include "Includes/push_swap.h"

void    swap_A(t_stack *stackA, t_stack *stackB)
{
    t_node  *newA;
    // t_node  *newB;

    (void)stackB;
    (void)stackA;

    newA = ft_lstlast(stackA->node)->previous;    
    ft_lstlast(stackA->node)->previous = newA->previous;
    newA->previous->next = ft_lstlast(stackA->node);
    newA->previous = newA->previous->next;
    newA->previous->next = newA;
    newA->next = NULL;
}


void     checker(char *ins, t_stack *stackA, t_stack *stackB)
{
    printf("isntruction to execute - [%s]\n", ins);
    if (!ft_strncmp(ins, "SA", 2))
        swap_A(stackA, stackB);
}