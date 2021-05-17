#include "../Includes/push_swap.h"

int		ft_isspace_isdigit(char c, char d)
{
	if (d == 's')
	{
		if (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r')
			return (1);
	}
	else if (d == 'd')
	{
		if (c >= 48 && c <= 57)
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



int		ft_atoi(const char *str)
{
	//Check atoi for int max and min pending
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while (ft_isspace_isdigit(*str, 's'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{   
			result *= 10;
			result += (*(str++) - '0');
		}
		else
			return (result * sign);
	}
	return (result * sign);
}























// static	int	check_num(long num, int neg)
// {
// 	if (neg > 0 && num > 2147483647)
// 		return (-1);
// 	else if (neg < 0 && num > 2147483648)
// 		return (0);
// 	return (num * neg);
// }

// int			ft_atoi(const char *str)
// {
// 	long	num;
// 	int		neg;

// 	num = 0;
// 	neg = 1;
// 	printf("str in atoi - [%s]\n", str);
// 	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
// 	|| *str == '\f' || *str == '\r')
// 		str++;
// 	if (*str == 45 || *str == 43)
// 	{
// 		if (*str == 45)
// 			neg = -1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		num = num * 10 + (*str - 48);
// 		if (num > 21474836470)
// 			break ;
// 		str++;
// 	}
// 	printf("str in atoi - [%s]\n", str);
// 	num = check_num(num, neg);
// 	return (num);
// }


