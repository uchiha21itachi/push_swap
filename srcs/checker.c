#include "Includes/push_swap.h"

// void    swap_A(t_stack *stackA, t_stack *stackB)
// {
//     t_node  *newA;
//     // t_node  *newB;

//     (void)stackB;
    
//     if (stackA->length < 2)
//         return ; 
//     newA = ft_lstlast(stackA->node)->previous;
//     if (stackA->length == 2)
//     {
//         newA->next->previous = NULL;
//         newA->previous = newA->next;
//         newA->next = NULL;
//         newA->previous->next = newA;
//         stackA->node = newA->previous;
//         return ;
//     }
//     ft_lstlast(stackA->node)->previous = newA->previous;
//     newA->previous->next = ft_lstlast(stackA->node);
//     newA->previous = newA->previous->next;
//     newA->previous->next = newA;
//     newA->next = NULL;
// }

void    swap_A(t_stack *stackA, t_stack *stackB)
{
    t_node  *newA;
    // t_node  *newB;

    (void)stackB;
    
    if (stackA->length < 2)
        return ; 
    newA = stackA->node->next;
    // if (stackA->length == 2)
    // {
    //     newA->next->previous = NULL;
    //     newA->previous = newA->next;
    //     newA->next = NULL;
    //     newA->previous->next = newA;
    //     stackA->node = newA->previous;
    //     return ;
    // }
    // newA->previous = stackA->node;
    // stackA->node->next->previous = NULL;
    print_desc(stackA->node);
    printf("\n\n");
    print_desc(newA);
    // newA->previous->next = newA;
    // printf("\n\n");
    // print_desc(stackA->node);
    // printf("\n\n");
    // print_desc(newA);
}



void     checker(char *ins, t_stack *stackA, t_stack *stackB)
{
    printf("\n\ninstruction to execute - [%s]\n", ins);
    if (!ft_strncmp(ins, "SA", 2))
        swap_A(stackA, stackB);
}