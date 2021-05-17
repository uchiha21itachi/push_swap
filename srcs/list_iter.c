#include "../Includes/push_swap.h"


t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	p = lst;
	if (lst == NULL)
		return (NULL);
	while (p->next != NULL)
		p = p->next;
	return (p);
}

int	ft_lstsize(t_list *lst)
{
	int		l;
	t_list	*new;

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
