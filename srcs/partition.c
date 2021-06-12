#include "../Includes/push_swap.h"


void    og_data_init(t_stack *stackA, t_data *data)
{
    t_node *node;
    int     i;

    i = 0;

    node = stackA->node;
    while (node)
    {
        data->og_stack[i] = node->number;
        data->req_pos[i] = node->number;
        data->og_pos[i] = i + 1;
        i++;
        node = node->next;
    }
    sort_number(data, stackA->length);
}

// void        fill_chunks(t_stack *stackA, t_stack *stackB, t_data *data)
// {
//     int i;

//     i = 0;
//     while (i < data->chunks_len)
//     {
//         data->chunks->num = i;
//         data
//         i++;
//     }
// }

void       create_chunks(t_stack *stackA, t_stack *stackB, t_data *data)
{
    t_chunks   chunks[data->chunks_len];
    int         i;


    i = 0;
    og_data_init(stackA, data);

    // chunks = (t_chunks **)malloc(sizeof(t_chunks *) * data->chunks_len);
    // if(!chunks)
    //     printf("malloc error chunks\n");
    // while (i < data->chunks_len)
    // {
    //     chunks[i] = (t_chunks *)malloc(sizeof(t_chunks *));
    //         if (!(chunks[i]))
    //             printf("malloc error\n");
    //     i++;
    // }
    // printf("chunk_num [%d]\n", chunks[0]->num);
    
    // chunks[0]->num = 1;
    // chunks[1]->num = 2;
    // chunks[2]->num = 3;
    // chunks[3]->num = 4;
    // chunks[4]->num = 5;
    // i = -1;
    // while (++i < 5)
    //     printf("chunk_num [%d]\n", chunks[i]->num);
    // // fill_chunks(stackA, stackB, data);
    (void)stackB;    
}