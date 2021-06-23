/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:09:45 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:09:47 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		printf("malloc error in stack init\n");
		return (NULL);
	}
	stack->length = 0;
	stack->node = NULL;
	stack->moves = NULL;
	return (stack);
}

t_stack	*insert_number(int num, t_stack *stack)
{
	t_node	*new;

	new = ft_lstnew(num);
	if (stack->length == 0)
		stack->node = new;
	else
		ft_lstadd_back(stack, new);
	stack->length++;
	return (stack);
}

void	fill_stack(char **argv, t_stack *stack)
{
	char	*args;
	int		number;
	char	*temps;

	args = ft_strdup(argv[1]);
	temps = args;
	while (*temps != '\0')
	{
		number = ft_atoi(temps);
		temps = remove_space_digit(temps, 'b');
		stack = insert_number(number, stack);
	}
	free(args);
}	

t_data	*data_init(t_stack *stackA)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		printf("malloc error datainit01");
		return (NULL);
	}
	data->max = 0;
	data->min = 0;
	data->med = 0;
	data->med_pos = -1;
	data->max_pos = -1;
	data->min_pos = -1;
	data->hold_one = 0;
	data->hold_one_pos = 0;
	data->hold_two = 0;
	data->hold_two_pos = 0;
	data->stack_len = stackA->length;
	data->chunks_div = 20;
	data->chunks_len = stackA->length / data->chunks_div;
	if (stackA->length % data->chunks_div != 0)
		data->chunks_len++;
	return (data);
}
