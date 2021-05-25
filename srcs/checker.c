#include "Includes/push_swap.h"

void    swap_A(t_stack *stackA, t_stack *stackB)
{
    t_node  *newA;
    // t_node  *newB;

    (void)stackB;
    (void)stackA;

    printf("\n----------stackA--------\n");
    print_desc(stackA->node);

    newA = ft_lstlast(stackA->node)->previous;
    printf("\n----------newA--------\n");
    print_desc(newA);

    ft_lstlast(stackA->node)->previous = newA->previous;
    printf("\n----------stackA--------\n");
    print_desc(stackA->node);

    newA->previous->next = ft_lstlast(stackA->node);
    printf("\n----------newA--------\n");
    print_desc(newA);


    newA->previous = newA->previous->next;
    printf("\n----------newA--------\n");
    print_desc(newA);

    newA->previous->next = newA;
    newA->next = NULL;
    printf("\n----------newA--------\n");
    print_desc(newA);


    printf("\n----------stackA--------\n");
    print_desc(stackA->node);

    // newA = stackA->node->next;
    // newA->previous = NULL;
    // newB = stackA->node;
    // newB->next = NULL;
    // newB = NULL;
    // newA = NULL;
}


void     checker(char *ins, t_stack *stackA, t_stack *stackB)
{
    printf("isntruction to execute - [%s]\n", ins);
    if (!ft_strncmp(ins, "SA", 2))
        swap_A(stackA, stackB);
}