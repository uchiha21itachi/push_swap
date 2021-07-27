/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:07:39 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/29 04:38:13 by yassharm         ###   ########.fr       */
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
			free(line);
			return (-1);
		}
		exec(line, stackA, stackB);
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	return (sort = check_sorted(stackA, stackB));
}

void	print_ret(int i)
{
	if (i == 0)
		ft_putstr("KO\n");
	else if (i < 0)
		ft_putstr("Error\n");
	else
		ft_putstr("OK\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;
	int		i;

	stackA = stack_init();
	stackB = stack_init();
	fill_stack(argc, argv, stackA);
	if (stackA->error != 0)
	{
		ft_putstr("Error\n");
		free_all(stackA, stackB);
		return (1);
	}
	if (stackA->length <= 0)
	{
		free_all(stackA, stackB);
		return (0);
	}		
	i = temp_caller(stackA, stackB);
	free_all(stackA, stackB);
	print_ret(i);	
	return (1);
}
