#include "Includes/push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		printf("malloc error in stack init\n");
		return (NULL);
	}
	stack->length = 0;
	stack->node = NULL;
	stack->moves = NULL;
	return (stack);
}

t_stack		*insert_number(int num, t_stack *stack)
{
	t_node	*new;

	new = ft_lstnew(num);
	if (stack->length == 0)
		stack->node = new;
	else
		ft_lstadd_back(stack, new);
	stack->length++;

	return(stack);
}

void		fill_stack(char **argv, t_stack *stack)
{
	char	*args;
	int		number;
	char	*temps;

	args = ft_strdup(argv[1]);
	temps = args;
	while (*temps != '\0')
	{
		number = ft_atoi(temps);
		temps = remove_space_digit(temps, 'b');
		stack = insert_number(number, stack);
	}
	free(args);
}	

void	add_move_back(t_stack *stackA, t_move *move)
{
	t_move	*new;

	new = stackA->moves;
	while (new->next != NULL)
		new = new->next;
	move->mov_num = new->mov_num + 1;
	new->next = move;
}

void	update_moves(t_stack *stackA, char *ins)
{
	t_move	*move;

	move = new_move();
	if (move == NULL)
		return;
	move->ins = ft_strdup(ins);
	if (stackA->moves == NULL)
	{
		move->mov_num = 1;
		stackA->moves = move;
		return;
	}
	add_move_back(stackA, move);
}


t_data 	*data_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		printf("malloc error");
		return (NULL);
	}
	data->max = 0;
	data->min = 0;
	data->med = 0;
	data->med_pos = 0;
	data->max_pos = 0;
	data->min_pos = 0;
	data->hold_one = 0;
	data->hold_two = 0;
	return (data);
}