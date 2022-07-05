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
	void	(*rotate_b)(t_list **, int);
	t_list *a;
	t_list *b;
	t_move	moves;

	a = lstdup(lst_a);
	b = lstdup(lst_b);
	rotate_b = &lstrotate;
	assign_moves(&moves);
	assign_min(a);
	assign_min(b);
	spot(a, b);
	print_list(a);
	print_list(b);
	rotate_a = &rra;
	rev = &(moves.rra);
	if (b->num < get_min_not_weird(a) || b->num > get_max_not_weird(a))
	{
		if (_max(a) < lstsize(a) / 2)
		{
			rev = &(moves.ra);
			rotate_a = &lstrotate;
		}
		while (!(a->num == get_min_not_weird(a) && a->head))
		{
			*rev += 1;
			rotate_a(&a, 2);
			// print_list(a);
		}
		if (b->num > get_max_not_weird(a))
			moves.rra_end = 1;
	}
	else
	{
		if (choose_rotate(a, b) < lstsize(a) / 2)
		{
			rotate_a = &lstrotate;
			rev = &(moves.ra);
		}
		while (!(b->num > a->num && b->num < a->next->num && a->head))
		{
			rotate_a(&a, 2);
			*rev += 1;
		}
		moves.sa = 1;
	}
	moves.pb = 1;
	if (b->spot > size / 2)
		moves.rrb = size - b->spot;
	else
		moves.rb = b->spot;
	free(a);
	free(b);
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