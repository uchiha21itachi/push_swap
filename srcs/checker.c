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

int	check_valid_ins(char *str)
{
	char	*line;

	line = str;
	if (ft_strncmp(line, "RA", 3)
		&& ft_strncmp(line, "RB", 3)
		&& ft_strncmp(line, "RRA", 3)
		&& ft_strncmp(line, "RRB", 3)
		&& ft_strncmp(line, "RR", 3)
		&& ft_strncmp(line, "RRR", 3)
		&& ft_strncmp(line, "PA", 3)
		&& ft_strncmp(line, "PB", 3)
		&& ft_strncmp(line, "SB", 3)
		&& ft_strncmp(line, "SA", 3)
		&& ft_strncmp(line, "SS", 3))
	{
		return (-1);
	}
	return (0);
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
	i = check_valid_ins(line);
	if (i < 0)
		return (0);
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
			stackA->error = 3;
		exec(line, stackA, stackB);
		free(line);
		if (stackA->error == 0)
			ret = get_next_line(fd, &line);
		else
			ret = 0;
	}
	if (stackA->error == 0)
		free(line);
	if (stackA->error > 0)
		return (-1);
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
