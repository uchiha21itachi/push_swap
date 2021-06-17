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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int x;

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
			x = *(unsigned char*)s1 - *(unsigned char*)s2;
			break ;
		}
	}
	return (x);
}

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
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
