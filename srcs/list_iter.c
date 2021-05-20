#include "../Includes/push_swap.h"


t_node	*ft_lstlast(t_node *lst)
{
	t_node	*p;

	p = lst;
	if (lst == NULL)
		return (NULL);
	while (p->next != NULL)
		p = p->next;
	return (p);
}

int	ft_lstsize(t_node *lst)
{
	int		l;
	t_node	*new;

	l = 0;
	if (!lst)
		return (0);
	new = lst;
	while (new != NULL)
	{
		new = new->next;
		l++;
	}
	return (l);
}
