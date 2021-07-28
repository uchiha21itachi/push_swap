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
		ft_putstr(temp->ins);
		ft_putstr("\n");
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

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	stackA = stack_init();
	stackB = stack_init();
	fill_stack(argc, argv, stackA);
	if (stackA->error == 0 && stackA->length > 0)
		moves_creator(stackA, stackB);
	else if (stackA->error != 0)
		ft_putstr("Error in Args \n");
	print_moves(stackA->moves);
	free_all(stackA, stackB);
	return (0);
}
