/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:08:44 by yassharm          #+#    #+#             */
/*   Updated: 2021/06/23 06:08:46 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isspace_isdigit(char c, char d)
{
	if (d == 's')
	{
		if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
			return (1);
	}
	else if (d == 'd')
	{
		if (c >= 48 && c <= 57)
			return (1);
	}
	else if (d == 'b')
	{
		if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r'
			|| (c >= 48 && c <= 57))
			return (1);
	}
	return (0);
}

char	*remove_space_digit(char *line, char c)
{
	if (c == 's')
	{
		while (ft_isspace_isdigit(*line, 's'))
			line++;
	}
	else if (c == 'd')
	{
		while (ft_isspace_isdigit(*line, 'd'))
			line++;
	}
	else if (c == 'b')
	{
		while (ft_isspace_isdigit(*line, 's'))
			line++;
		if (*line == '+' || *line == '-')
			line++;
		while (ft_isspace_isdigit(*line, 'd'))
			line++;
	}
	return (line);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	x;

	x = 0;
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
		{
			x = *(unsigned char *)s1 - *(unsigned char *)s2;
			break ;
		}
	}
	return (x);
}

static	int	check_num(long num, int neg, t_stack *stack)
{
	if (neg > 0 && num > 2147483647)
	{
		stack->error = 2;
		return (0);
	}
	else if (neg < 0 && num > 2147483648)
	{
		stack->error = 2;
		return (0);
	}
	return (num * neg);
}

int			ft_atoi_err(const char *str, t_stack *stack)
{
	long	num;
	int		neg;

	num = 0;
	neg = 1;

	while (ft_isspace_isdigit(*str, 's'))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			neg = -1;
		str++;
	}
	if (str[0] != '\0')
	{
		if (!(ft_isspace_isdigit(str[0], 'd')))
			stack->error = 2;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		if (num > 21474836470)
			break ;
		str++;
	}
	num = check_num(num, neg, stack);
	return (num);
}