#include "Includes/push_swap.h"


void    swap_A_B(t_stack *stackA)
{
    t_node  *newA;

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

    if (stackA->length < 1)
        return;
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

    if (stackA->length < 2)
        return;
    newA = stackA->node->next;
    stackA->node->previous = ft_lstlast(newA);
    ft_lstlast(newA)->next = newA->previous;
    stackA->node->next = NULL;
    newA->previous = NULL;
    stackA->node = newA;
}

void     reverse_rotate(t_stack *stackA)
{   
    t_node *newA;

    if (stackA->length < 2)
        return;
    newA = ft_lstlast(stackA->node);
    newA->previous->next = NULL;
    newA->previous = NULL;
    ft_lstadd_front(stackA, newA);
}

int    exec_helper(char *ins, t_stack *stackA, t_stack *stackB)
{
    if (!ft_strncmp(ins, "RRA", 3))
        reverse_rotate(stackA);
    else if (!ft_strncmp(ins, "RRB", 3))
        reverse_rotate(stackB);
    else if (!ft_strncmp(ins, "RRR", 3))
    {
        reverse_rotate(stackA);
        reverse_rotate(stackB);
    }
    else if (!ft_strncmp(ins, "RA", 3))
        rotate_ra(stackA);
    else if (!ft_strncmp(ins, "RB", 3))
        rotate_ra(stackB);
    else if (!ft_strncmp(ins, "RR", 3))
    {
        rotate_ra(stackA);
        rotate_ra(stackB);
    }
    else
    {
		printf("Wrong Move Input. Please enter again\n");
        return (0);
    }
    return (1);
}

void     exec(char *ins, t_stack *stackA, t_stack *stackB)
{
    int     i;

    i = 1;
    printf("\n\ninstruction to execute - [%s]\n", ins);
    
    if (!ft_strncmp(ins, "R", 1))
        i   = exec_helper(ins, stackA, stackB);
    else
    {

        if (!ft_strncmp(ins, "SA", 3))
            swap_A_B(stackA);
        else if (!ft_strncmp(ins, "SB", 3))
            swap_A_B(stackB);
        else if (!ft_strncmp(ins, "SS", 3))
        {
            swap_A_B(stackA);
            swap_A_B(stackB);
        }
        else if (!ft_strncmp(ins, "PA", 3))
            push_A_B(stackB, stackA);
        else if (!ft_strncmp(ins, "PB", 3))
            push_A_B(stackA, stackB);
        else
        {
    		printf("Wrong Move Input. Please enter again\n");
            i = 0;
        }
    }
    if (i == 1)
        update_moves(stackA, ins);
	print_both(stackA->node, stackB->node);
}   