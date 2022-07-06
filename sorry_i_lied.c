#include "push_swap.h"

t_list	*lstdup(t_list *lst);

void	assign_moves(t_move *moves)
{
	moves->pb = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->sa = 0;
	moves->rra_end = 0;
}

void	spot(t_list *a, t_list *b)
{
	int	i;

	i = 0;
	if (a)
	{
		while (1)
		{
			a->spot = i;
			a = a->next;
			if (a->head)
				break ;
			i++;
		}
	}
	i = 0;
	if (b)
	{
		while (1)
		{
			b->spot = i;
			i++;
			b = b->next;
			if (b->head)
				break ;
		}
	}
}

t_move	calculate(t_list *lst_a, t_list *lst_b, int size)
{
	int		*rev;
	int		*rb;
	void	(*rotate_a)(t_list **, int);
	t_list *a;
	t_list *b;
	t_move	moves;

	a = lstdup(lst_a);
	b = lstdup(lst_b);
	assign_moves(&moves);
	// print_list(a);
	// print_list(b);
	rotate_a = &rra;
	rev = &(moves.rra);
	if (b->num > get_max_not_weird(a) || b->num < get_min_not_weird(a))
	{
		if (_max(a) > lstsize(a) / 2)
			moves.rra = lstsize(a) - _max(a);
		else
			moves.ra = _max(a);
		if (b->num > get_max_not_weird(a))
			moves.rra_end = 1;
	}
	else
	{
		int i = 0;
		while (!(b->num > a->num && b->num < a->next->num))
		{
			// print_list(a);
			i++;
			lstrotate(&a, 2);
		}
		moves.ra = i;
		moves.sa = 1;
	}
	moves.pb = 1;
	if (b->spot > size / 2)
		moves.rrb = size - b->spot;
	else
		moves.rb = b->spot;
	free(a);
	free(b);
	// printf("IN CALCULATE ");
	// print_moves(moves);
	return (moves);
}

t_list	*lstdup(t_list *lst)
{
	t_list	*new;
	t_list	*tmp;

	new = lstnew(lst->num, -1, NULL);
	if (!new)
		return (NULL);
	tmp = new;
	tmp->head = 1;
	new->spot = lst->spot;
	lst = lst->next;
	new->index = -1;
	while (1)
	{
		if (lst->head)
			break ;
		new->next = lstnew(lst->num, -1, NULL);
		if (!new->next)
			return (NULL);
		new->next->spot = lst->spot;
		lst = lst->next;
		new = new->next;
		new->index = -1;
	}
	new->next = tmp;
	return (tmp);
}