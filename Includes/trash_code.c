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






// void    fix_med_pos(t_stack *stackA, t_data *data)
// {
//     t_node *node;
//     int     diff;
//     int     diff2;
//     int     i;
//     int     med;

//     node = stackA->node;
//     i = 1;
//     med = data->med;
//     data->med = node->number;
//     data->med_pos = 1; 
//     diff2 = 0;
//     diff = 0;
//     while (node)
//     {
//         diff = med - data->med;
//         diff2 = med - node->number;
//         printf("\n\n\n");
//         printf("data->med [%d] diff [%d]\n", data->med, diff );
//         printf("number [%d] diff2 [%d] \n", node->number, diff2);
//         if (diff < 0)
//             diff = diff * (-1); 
//         if (diff2 < 0)
//             diff2 = diff2 * (-1);
//         if (diff > diff2)
//         {
//             data->med = node->number;
//             data->med_pos = i + 1;
//         }
//         i++;
//         node = node->next;
//     }
//     printf("\n\n\n\n");
// }

// void    get_median(t_stack *stack, t_data *data)
// {
//     t_node  *node;
//     int     i;

//     node = stack->node;
//     i = 0;
//     data->min = node->number;
// 	data->max = node->number;
// 	while (node)
// 	{
// 		if (data->min > node->number)
// 			data->min = node->number;
// 		if (data->max < node->number)
// 			data->max = node->number;
// 		node = node->next;
// 	}
//     data->med = (data->max + data->min) / 2;
//     node = stack->node;
//     while (node)
//     {
//         i++;
//         if (node->number == data->med)
//             data->med_pos = i;
//         if (node->number == data->max)
//             data->max_pos = i;
//         if (node->number == data->min)
//             data->min_pos = i;
//         node = node->next;
//     }
//     if (data->med_pos == -1)
//         fix_med_pos(stack, data);
//     printf("max [%d] min [%d] med_num [%d] med_pos [%d]\n", data->max, data->min, data->med, data->med_pos);
// }



// void     get_min_pos(t_node *node, t_data *data)
// {
//     t_node  *temp;
//     int     i;

//     i = 0;
//     temp = node;
//     while (temp)
//     {
//         i++;
//         if (temp->number == data->min)
//             data->min_pos = i;
//         temp = temp->next;
//     }
// }

// void    update_min(t_node *node, t_data *data)
// {
//     t_node  *temp;
//     int     i;

//     i = 0;
//     temp = node;
//     data->min = temp->number;
//     while (temp)
//     {
//         i++;
//         if (data->min > temp->number)
//             data->min = temp->number;
//         temp = temp->next;
//     }
//     get_min_pos(node, data);
// }
