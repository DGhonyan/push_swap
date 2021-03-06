/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:28:03 by dghonyan          #+#    #+#             */
/*   Updated: 2022/06/22 11:28:05 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_swap(t_list **lst)
{
	swap(lst);
	_index(*lst);
	mark_to_move(*lst);
	ft_printf("sa\n");
}

void	pb(t_list **lst, t_list **b)
{
	push_b(*lst, b, 0);
	lstdel(lst);
	_index(*lst);
	ft_printf("pb\n");
}

void	lstrotate(t_list **lst, int b)
{
	while (*lst)
	{
		*lst = (*lst)->next;
		if ((*lst)->head == true)
		{
			(*lst)->head = false;
			(*lst) = (*lst)->next;
			(*lst)->head = true;
			break ;
		}
	}
	if (b == 1)
		ft_printf("rb\n");
	else if (b == 0)
		ft_printf("ra\n");
}

void	rra(t_list **lst, int b)
{
	while (*lst)
	{
		*lst = (*lst)->next;
		if ((*lst)->next->head == true)
		{
			(*lst)->next->head = false;
			(*lst)->head = true;
			break ;
		}
	}
	if (b == 1)
		ft_printf("rrb\n");
	else if (b == 0)
		ft_printf("rra\n");
}
