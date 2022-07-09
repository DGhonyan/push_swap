/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:27:53 by dghonyan          #+#    #+#             */
/*   Updated: 2022/07/07 18:27:56 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_count(t_move moves)
{
	return (moves.pb + moves.ra + moves.rb
		+ moves.rra + moves.rrb + moves.sa + moves.rra_end);
}

void	eh(t_list **a, void (**rotate)(t_list **, int))
{
	*rotate = &lstrotate;
	if (_max(*a) > lstsize(*a) / 2)
		*rotate = &rra;
	while (!is_sorted_break(*a))
		(*rotate)(a, 0);
}

void	one_last_thing(t_list *a)
{
	t_list	*b;

	b = NULL;
	while (lstsize(a) != 3)
		pb(&a, &b);
	if (a->num == get_max_not_weird(a))
		lstrotate(&a, 0);
	if (a->next->num > a->next->next->num)
		rra(&a, 0);
	if (a->num > a->next->num)
		list_swap(&a);
	is_sorted(a, b);
	sort_a(a, b);
}
