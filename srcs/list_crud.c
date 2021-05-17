#include "../Includes/push_swap.h"


t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (new == 0)
		return ;
	new->next = *alst;
	*alst = new;
}


void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ls;
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
	ls->next = new;
}
