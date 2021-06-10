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

    while (i < stackA->length)
    {
        printf("OG [pos] [num] ---- [%d] [%d]\n", data->og_pos[i], data->og_stack[i]);
        i++;
    }
    printf("SORTED VERSION---------------------\n");
    print_array(data->req_pos, stackA->length);
}

void       create_chunks(t_stack *stackA, t_stack *stackB, t_data *data)
{
    int     i;
    int     chunks;

    i = 0;
    chunks = stackA->length / 20;
    if (stackA->length % 20  != 0)
        chunks++;
    printf("number of chunks - [%d]\n", chunks);
    data->chunks = (t_chunks *)malloc(sizeof(t_chunks) * chunks);
    
    
    
    
    og_data_init(stackA, data);
    (void)stackB;    

    /*
        data struct chunks
            chunk_number;
            chunk_members[chunk_size];
            chunk_median;
            chunk_max;
            chunk_min;
            chunk_length;

        create array for chunks[no of chunks]
        set_median and min max
        allot all number chunks

    */
}