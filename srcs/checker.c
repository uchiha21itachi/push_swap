/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:07:39 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:07:42 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	temp_caller(t_stack *stackA, t_stack *stackB)
{
	int		fd;
	char	*line;
	int		ret;
	int		sort;

	fd = 0;
	sort = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		if (check_line(line) != 1)
		{
			printf("Wrong Move Input. Please enter again\n");
			free(line);
			return (-1);
		}
		exec(line, stackA, stackB);
		free(line);
		if (sort == 1)
			printf("Congratulations stack sorted\n Press enter to exit\n");
		ret = get_next_line(fd, &line);
	}
	free(line);
	return (sort = check_sorted(stackA, stackB));
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;
	int		i;

	(void)argv;
	if (argc != 2)
	{
		printf("Error - Please enter ARG as arguments\n");
		return (0);
	}
	stackA = stack_init();
	stackB = stack_init();
	fill_stack(argv, stackA);
	i = temp_caller(stackA, stackB);
	if (stackA->length > 500 || stackA->length < 0)
		i = -1;
	free_all(stackA, stackB);
	if (i == 0)
		printf("KO");
	else if (i < 0)
		printf("ERROR");
	else
		printf("OK");
	return (1);
}
