#include "../Includes/push_swap.h"


t_node	*ft_lstnew(int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		return (NULL);
	new->number = number;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	ft_lstadd_front(t_node **alst, t_node *new)
{
	if (!alst)
		return ;
	if (new == 0)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_lstadd_back(t_node **alst, t_node *new)
{
	t_node *ls;
	if (!alst)
		return ;
	if (*alst)
		ls = *alst;
	else
	{
		*alst = new;
		return ;
	}
	while (ls->next != NULL)
		ls = ls->next;
	new->previous = ls;
	ls->next = new;
}


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