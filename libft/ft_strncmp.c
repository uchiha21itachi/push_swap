#include "../Includes/push_swap.h"

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
