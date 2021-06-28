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

void	check_dup_number(int number, t_stack *stack)
{
	t_node	*node;

	node = stack->node;
	while (node)
	{
		if (node->number == number)
			stack->error = 2;
		node = node->next;
	}
}

void	check_args(char *temps, t_stack *stack)
{
	int	number;
	int i;

	i = 0;
	while (temps[i] != '\0')
	{
		if (!ft_isspace_isdigit(temps[i], 'b') && temps[i] != '-')
		{
			stack->error = 1;
			return;
		}
		i++;
	}
	while (*temps != '\0')
	{
		while (ft_isspace_isdigit(*temps, 's'))
			temps++;
		if (*temps != '\0')
		{
			number = ft_atoi(temps);
			check_dup_number(number, stack);
			temps = remove_space_digit(temps, 'b');
			stack = insert_number(number, stack);
		}
	}
}

void	fill_stack(int argc, char **argv, t_stack *stack)
{
	char	*args;
	char	*temps;
	int		i;

	i = 1;
	args = ft_strdup("");
	while (i < argc)
	{
		temps = args;
		args = ft_strjoin(temps, argv[i]);
		free(temps);
		temps = args;
		args = ft_strjoin(temps, " ");
		free(temps);
		i++;
	}
	temps = args;
	check_args(temps, stack);
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
