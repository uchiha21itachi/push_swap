#include "Includes/push_swap.h"

void    swap_A(t_stack *stackA, t_stack *stackB)
{
    // t_node  *newA;
    // t_node  *newB;

    (void)stackB;
    (void)stackA;
    print_desc(stackA);

    // newA = ft_lstlast(stackA->node)->previous;
    // printf("--------Step 1------------\n");
    // printf("---------------newA----------\n");
    // print_stack(newA);
    // printf("--------------stackA----------\n");
    // print_stack(stackA->node);


    // printf("\n\n--------Step 2------------\n");
    // ft_lstlast(stackA->node)->previous = newA->previous;
    // printf("---------------newA----------\n");
    // print_stack(newA);
    // printf("--------------stackA----------\n");
    // print_stack(stackA->node);


    // printf("\n\n--------Step 3------------\n");
    // newA->previous->next = ft_lstlast(stackA->node);
    // printf("---------------newA----------\n");
    // print_stack(newA);
    // printf("--------------stackA----------\n");
    // print_stack(stackA->node);


    // printf("\n\n--------Step 4------------\n");
    // newA->previous = newA->previous->next;
    // printf("---------------newA----------\n");
    // print_stack(newA);
    // printf("--------------stackA----------\n");
    // print_stack(stackA->node);


    // newA = stackA->node->next;
    // newA->previous = NULL;
    // newB = stackA->node;
    // newB->next = NULL;
    // newB = NULL;
    // newA = NULL;
    // print_numbers(newA, 'C');
}


void     checker(char *ins, t_stack *stackA, t_stack *stackB)
{
    printf("isntruction to execute - [%s]\n", ins);
    if (!ft_strncmp(ins, "SA", 2))
        swap_A(stackA, stackB);
}