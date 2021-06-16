// int     get_req_pos(t_data *data, int num, int len)
// {
//     int i;

//     i = 0;
//     while (i < len)
//     {
//         if (num == data->req_pos[i])
//             return (i+1);
//         i++;
//     }
//     return (-1);
// }

// void    cal_stackB_rot(t_stack *stackA, t_stack *stackB, int req_pos)
// {
//     int m1;
//     int m2;
//     int temp;

//     temp = 0;
//     m1 = req_pos - 1;
//     m2 = (stackB->length - req_pos) + 1;
//     if (m1 < m2)
//     {
//         while (temp != m1)
//         {
//             exec("RRB", stackA, stackB);
//             temp++;
//         }
//     }
//     else
//     {
//         while (temp != m2)
//         {
//             exec("RB", stackA, stackB);
//             temp++;
//         }
//     }
// }


// int     get_opt_rot(t_stack *stackA, t_data *data, int j)
// {
//     t_node *node;
//     int     i;
//     int     pos1;

//     i = 0;
//     pos1 = 0;
//     node = stackA->node;
//     while (node)
//     {
//         if (node->number == data->chunks[j]->min)
//             pos1 = i + 1;
//         i++;
//         node = node->next; 
//     }
//     if ((pos1 -1) >= (stackA->length - pos1) + 1)
//         return (1);
//     else if ((pos1 -1) < (stackA->length - pos1) + 1)
//         return (2);
//     return (-1);
// }









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



// void   sort_stackB(t_stack *stackA, t_stack *stackB, int req_pos, int stop_num)
// {
//     if (req_pos == 2)
//         exec("SB", stackA, stackB);
//     else if (req_pos == stackB->length)
//         exec("RB", stackA, stackB);
//     else if (req_pos > 2 && req_pos != stackB->length)
//     {
//             while (stackB->node->next->number != stop_num)
//             {
//                 if(req_pos <= stackB->length / 2)
//                 {
//                     exec("SB", stackA, stackB);
//                     exec("RB", stackA, stackB);
//                 }
//                 else
//                 {
//                     exec("RRB", stackA, stackB);
//                     exec("SB", stackA, stackB);
//                 }
//             }
//         cal_stackB_rot(stackA, stackB, req_pos);
//     }
// }


// void    sort_stackB_start(t_stack *stackA, t_stack *stackB)
// {
//     int     num;
//     int     stop_num;
//     t_node  *temp;
//     int     pos;
//     int     req_pos;

//     num = stackB->node->number;
//     temp = stackB->node;
//     pos = 0;
//     req_pos = 0;
//     stop_num = 0;
//     while (temp)
//     {
//         pos++;
//         if(temp->number > num)
//         {
//             req_pos = pos;
//             if(temp->next != NULL)
//                 stop_num = temp->next->number;
//         }
//         temp = temp->next;
//     }
//     sort_stackB(stackA, stackB, req_pos, stop_num);
// }

// void    move_to_stackA(t_stack *stackA, t_stack *stackB, t_data *data, int j)
// {
//     int rot;

//     if (j == (data->chunks_len - 1))
//     {
//         while (stackB->length != 0)
//             exec("PA", stackA, stackB);
//     }
//     else 
//     {
//         rot = get_opt_rot(stackA, data, j+1);
//         while (stackA->node->number != data->chunks[j + 1]->min)
//         {    
//             if (rot == 1)
//                 exec("RRA", stackA, stackB);
//             else if (rot == 2)
//                 exec("RA", stackA, stackB);
//         }
//         while (stackB->length != 0)
//             exec("PA", stackA, stackB);
//     }

// }
