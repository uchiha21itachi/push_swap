/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 04:38:20 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/29 04:38:22 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->length = 0;
	stack->error = 0;
	stack->node = NULL;
	stack->moves = NULL;
	return (stack);
}

void	check_garbage(char c, t_stack *stack)
{
	if (c != '\0')
	{
		if (!(ft_isspace_isdigit(c, 'd')))
			stack->error = 2;
	}
}

void	ft_putstr(char *str)
{
	int		len;
	int		i;
	int		ret;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ret = write(1, &str[i], 1);
		i++;
	}
	(void)ret;
}

int	check_sorted(t_stack *stackA, t_stack *stackB)
{
	t_node	*temp;

	if (stackB->node != NULL)
		return (0);
	temp = stackA->node;
	while (temp->next != NULL)
	{
		if (!(temp->number < temp->next->number))
			return (0);
		temp = temp->next;
	}
	temp = NULL;
	return (1);
}

void	ft_tolower(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
}

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}
