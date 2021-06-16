#include "../Includes/push_swap.h"

void    og_data_init(t_stack *stackA, t_data *data)
{
    t_node *node;
    int     i;

    i = 0;

	data->og_stack = (int *)malloc(sizeof(int) * stackA->length);
    data->req_pos = (int *)malloc(sizeof(int) * stackA->length);
	if (data->og_stack == NULL || data->req_pos == NULL)
	{
		printf("malloc error ogdatainit01\n");
		return;
	}

    node = stackA->node;
    while (node)
    {
        data->og_stack[i] = node->number;
        data->req_pos[i] = node->number;
        i++;
        node = node->next;
    }
    sort_number(data, stackA->length);
}

void        fill_chunks(t_data *data, int i)
{
    int stop;
    int start;
    int n;

    stop = data->chunks[i]->num * data->chunks_div;
    start = (stop - data->chunks_div) + 1;
    if (stop > data->stack_len)
        stop = data->stack_len;
    data->chunks[i]->min = data->req_pos[start - 1];
    data->chunks[i]->max = data->req_pos[stop - 1];
    data->chunks[i]->med = data->req_pos[((start + stop) / 2) - 1];
    n = start - 1;
    while (n < stop)
    {
        data->chunks[i]->members[data->chunks[i]->length] = data->req_pos[n];
        data->chunks[i]->length++;
        n++;
    }
}

void       create_chunks(t_stack *stackA, t_stack *stackB, t_data *data)
{
    int         i;

    i = 0;
    og_data_init(stackA, data);
    data->chunks = (t_chunks **)malloc(sizeof(t_chunks *) * data->chunks_len);
    if(!data->chunks)
        printf("malloc error chunks\n");
    while (i < data->chunks_len)
    {
        data->chunks[i] = (t_chunks *)malloc(sizeof(t_chunks));
        data->chunks[i]->length = 0;
        data->chunks[i]->members = (int *)malloc(sizeof(int) * data->chunks_div); 
        data->chunks[i]->num = i+1;
        fill_chunks(data, i);
        i++;
    }
    // print_chunks_data(data);
    (void)stackB;    
}