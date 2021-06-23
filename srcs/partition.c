/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:09:26 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:09:28 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	heapify(int *arr, int n, int i)
{
	int	largest;
	int	left;
	int	right;

	largest = i;
	left = (2 * i) + 1;
	right = (2 * i) + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(arr, i, largest);
		heapify(arr, n, largest);
	}
}

void	sort_number(t_data *data, int n)
{
	int	i;

	i = (n / 2) - 1;
	while (i >= 0)
	{
		heapify(data->req_pos, n, i);
		i--;
	}
	i = n - 1;
	while (i >= 0)
	{
		swap(data->req_pos, 0, i);
		heapify(data->req_pos, i, 0);
		i--;
	}
}

void	og_data_init(t_stack *stackA, t_data *data)
{
	t_node	*node;
	int		i;

	i = 0;
	data->og_stack = (int *)malloc(sizeof(int) * stackA->length);
	data->req_pos = (int *)malloc(sizeof(int) * stackA->length);
	if (data->og_stack == NULL || data->req_pos == NULL)
	{
		printf("malloc error ogdatainit01\n");
		return ;
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

void	fill_chunks(t_data *data, int i)
{
	int	stop;
	int	start;
	int	n;

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

void	create_chunks(t_stack *stackA, t_stack *stackB, t_data *d)
{
	int	i;

	i = 0;
	og_data_init(stackA, d);
	d->chunks = (t_chunks **)malloc(sizeof(t_chunks *) * d->chunks_len);
	if (!d->chunks)
		printf("malloc error chunks\n");
	while (i < d->chunks_len)
	{
		d->chunks[i] = (t_chunks *)malloc(sizeof(t_chunks));
		d->chunks[i]->length = 0;
		d->chunks[i]->members = (int *)malloc(sizeof(int) * d->chunks_div);
		d->chunks[i]->num = i + 1;
		fill_chunks(d, i);
		i++;
	}
	(void)stackB;
}
