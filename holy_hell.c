#include "push_swap.h"

int	get_min_not_weird(t_list *a)
{
	int	min;

	min = INT_MAX;
	while (1)
	{
		if (a->num < min)
			min = a->num;
		a = a->next;
		if (a->head)
			break ;
	}
	return (min);
}

int	get_max_not_weird(t_list *a)
{
	int	min;

	min = INT_MIN;
	while (1)
	{
		if (a->num > min)
			min = a->num;
		a = a->next;
		if (a->head)
			break ;
	}
	return (min);
}


void	do_the_thing(t_move moves, t_list **a, t_list **b)
{
	int	r;
	int	rr;
	int	rotate;

	// while (moves.ra > 0 && moves.rb > 0)
	// {
	// 	lstrotate(a, 2);
	// 	lstrotate(b, 2);
	// 	ft_printf("rr\n");
	// 	moves.ra--;
	// 	moves.rb--;
	// }
	while (moves.ra > 0)
	{
		lstrotate(a, 0);
		moves.ra--;
	}
	while (moves.rb > 0)
	{
		lstrotate(b, 1);
		moves.rb--;
	}
	// while (moves.rra > 0 && moves.rrb > 0)
	// {
	// 	rra(a, 2);
	// 	rra(b, 2);
	// 	ft_printf("rrr\n");
	// 	moves.rra--;
	// 	moves.rrb--;
	// }
	while (moves.rra > 0)
	{
		rra(a, 0);
		moves.rra--;
	}
	while (moves.rrb > 0)
	{
		rra(b, 1);
		moves.rrb--;
	}
	if (moves.pb)
	{
		push_b(*b, a, 1);
		lstdel(b);
	}
	if (moves.sa)
	{
		list_swap(a);
	}
	if (moves.rra_end)
		lstrotate(a, 0);
	//printf("%d %d\n", r, rr);
}
