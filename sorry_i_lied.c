/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:28:49 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/27 19:31:46 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstdup(t_list *lst);

static void	norminette_again(t_list *a, t_list *b, t_move *moves)
{
	if (b->num > get_max_not_weird(a) || b->num < get_min_not_weird(a))
	{
		if (_max(a) > lstsize(a) / 2)
			moves->rra = lstsize(a) - _max(a);
		else
			moves->ra = _max(a);
		if (b->num > get_max_not_weird(a))
			moves->rra_end = 1;
	}
	else
	{
		if (choose_rotate(a, b) > lstsize(a) / 2)
			moves->rra = lstsize(a) - choose_rotate(a, b);
		else
			moves->ra = choose_rotate(a, b);
		moves->sa = 1;
	}
}

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
	while (a)
	{
		a->spot = i;
		a = a->next;
		if (a->head)
			break ;
		i++;
	}
	i = 0;
	while (b)
	{
		b->spot = i;
		i++;
		b = b->next;
		if (b->head)
			break ;
	}
}

t_move	calculate(t_list *lst_a, t_list *lst_b, int size)
{
	t_list	*a;
	t_list	*b;
	t_move	moves;

	a = NULL;
	b = NULL;
	a = lstdup(lst_a);
	b = lstdup(lst_b);
	if (!a || !b)
	{
		free(a);
		free(b);
		err_only_lst("bye (malloc failed)", lst_a, lst_b);
	}
	assign_moves(&moves);
	norminette_again(a, b, &moves);
	moves.pb = 1;
	moves.rb = b->spot;
	free_list(a);
	free_list(b);
	return (moves);
}
	// if (b->spot > size / 2)
	// 	moves.rrb = size - b->spot;
	// else
	// 	moves.rb = b->spot;

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
		new->next = lstnew(lst->num, lst->index, NULL);
		if (!new->next)
			return (NULL);
		new->next->spot = lst->spot;
		lst = lst->next;
		new = new->next;
		new->index = lst->index;
	}
	new->next = tmp;
	return (tmp);
}
