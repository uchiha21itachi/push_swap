/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:09:36 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:09:38 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_moves(t_move *move)
{
	t_move	*temp;

	temp = move;
	while (temp)
	{
		ft_tolower(temp->ins);
		printf("%s\n", temp->ins);
		temp = temp->next;
	}
}

int	check_line(char	*line)
{
	int	i;

	i = ft_strlen(line);
	if (i < 1 || i > 3)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		line[i] = ft_toupper(line[i]);
		i++;
	}
	return (1);
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

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	int i;
	i = 0;
	while (i < argc)
	{
		printf("[%s]\n", argv[i]);
		i++;
	}
	// if (argc != 2)
	// {
		// printf("Error - Please enter ARG as arguments\n");
		// return (0);
	// }
	(void)argc;
	stackA = stack_init();
	stackB = stack_init();
	fill_stack(argc, argv, stackA);
	moves_creator(stackA, stackB);
	print_moves(stackA->moves);
	free_all(stackA, stackB);
	return (0);
}

/* Need to check duplicates in arg
 Change printf and error mechanism */
