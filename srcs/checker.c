#include "Includes/push_swap.h"


void    swap_A_B(t_stack *stackA, t_stack *stackB, int n)
{
    t_node  *newA;

    if (n == 1)
        swap_A_B(stackB, stackA, 0);
  
    if (stackA->length < 2)
        return ;
    newA = stackA->node->next;
    if (stackA->length == 2)
    {
        newA->next = stackA->node;
        stackA->node->next = NULL;
        newA->previous = NULL;
        stackA->node->previous = newA;
        stackA->node = newA;
        return ;
    }
    stackA->node->next = newA->next;
    newA->next->previous = stackA->node;
    newA->next = newA->previous;
    newA->previous = NULL;
    stackA->node->previous = newA;
    stackA->node = newA;
}

void     push_A_B(t_stack *stackA, t_stack *stackB)
{
    t_node  *new;

    if (stackA->length < 2)
    {
        new = stackA->node;
        ft_lstadd_front(stackB, new);        
        stackA->node = NULL;
    }
    else
    {
        new = stackA->node->next;
        new->previous = NULL;
        stackA->node->next = NULL;
        ft_lstadd_front(stackB, stackA->node);
        stackA->node = new;
    }
    stackA->length--;
    stackB->length++;
}

void     rotate_ra(t_stack *stackA)
{   
    t_node *newA;

    newA = stackA->node->next;
    stackA->node->previous = ft_lstlast(newA);
    ft_lstlast(newA)->next = newA->previous;
    stackA->node->next = NULL;
    newA->previous = NULL;
    stackA->node = newA;
}

void     exec(char *ins, t_stack *stackA, t_stack *stackB)
{
    printf("\n\ninstruction to execute - [%s]\n", ins);
    if (!ft_strncmp(ins, "SA", 2))
        swap_A_B(stackA, stackB, 0);
    else if (!ft_strncmp(ins, "SB", 2))
        swap_A_B(stackA, stackB, 1);
    else if (!ft_strncmp(ins, "PA", 2))
        push_A_B(stackB, stackA);
    else if (!ft_strncmp(ins, "PB", 2))
        push_A_B(stackA, stackB);
    else if (!ft_strncmp(ins, "RA", 2))
        rotate_ra(stackA);
    else if (!ft_strncmp(ins, "RB", 2))
        rotate_ra(stackB);
}