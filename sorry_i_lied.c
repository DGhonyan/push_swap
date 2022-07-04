#include "push_swap.h"

t_list	*lstdup(t_list *lst);

void	assign_moves(t_move *moves)
{
	moves->ra = 0;
	moves->rra = 0;
	//moves->rb = 0;
	//moves->rrb = 0;
	moves->pb = 0;
	moves->sa = 0;
}

void	spot(t_list *a, t_list *b)
{
	int	i;

	i = 0;
	// print_list(a);
	// print_list(b);
	while (1)
	{
		a->spot = i;
		a = a->next;
		if (a->head)
			break ;
	}
	i = 0;
	while (1)
	{
		b->spot = i;
		b = b->next;
		if (b->head)
			break ;
	}
}

int	calculate(t_list *lst_a, t_list *lst_b)
{
	int		*rev;
	int		*rb;
	void	(*rotate_a)(t_list **, int);
	void	(*rotate_b)(t_list **, int);
	t_list *a;
	t_list *b;
	t_move	moves;

	rb = &(moves.rb);
	a = lstdup(lst_a);
	b = lstdup(lst_b);
	rotate_b = &lstrotate;
	assign_moves(&moves);
	// while (i--)
	// {
	rotate_a = &rra;
	rev = &(moves.rra);
	if (b->num < get_min(a) || b->num > get_max(a))
	{
		//printf("%d\n", b->num);
		if (_max(a) < lstsize(a) / 2)
		{
			rev = &(moves.ra);
			rotate_a = &lstrotate;
		}
		while (!(a->num == get_min(a) && a->head))
		{
			*rev += 1;
			rotate_a(&a, 2);
		}
		moves.pb++;
		if (b->num > get_max(a))
			*rev += 1;
	}
	else
	{
		if (choose_rotate(a, b) < lstsize(a) / 2)
		{
			rotate_a = &lstrotate;
			rev = &(moves.ra);
		}
		while (!(b->num > a->num && b->num < a->next->num))
		{
			rotate_a(&a, 2);
			*rev += 1;
		}
		moves.pb++;
		moves.sa++;
	}
	printf("\n%d %d %d %d %d\n", b->num, moves.ra, moves.rra, moves.sa, moves.pb);
	int d = b->spot;
	int c = lstsize(b);
	free(a);
	free(b);
	if (d > c / 2)
		return (moves.ra + moves.rra + moves.sa + moves.pb + c - d);
	return (moves.ra + moves.rra + moves.sa + moves.pb + d);
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
	lst = lst->next;
	while (1)
	{
		if (lst->head)
			break ;
		new->next = lstnew(lst->num, -1, NULL);
		if (!new->next)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	new->next = tmp;
	return (tmp);
}