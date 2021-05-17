#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../gnl/get_next_line.h"

typedef struct	s_list
{
	int			content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
int				ft_atoi(const char *str);
char			*remove_space_digit(char *line, char c);

#endif

