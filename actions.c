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
	//print_list(*lst);
}

void	pb(t_list **lst, t_list **b)
{
	push_b(*lst, b, 0);
	lstdel(lst);
	_index(*lst);
	mark_to_move(*lst);
	ft_printf("pb\n");
	// print_list(*b);
}

void	lstrotate(t_list **lst)
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
	ft_printf("ra\n");
	//print_list(*lst);
}

void	rra(t_list **lst)
{
	while (*lst)
	{
		*lst = (*lst)->next;
		if ((*lst)->next->head == true)
		{
			(*lst)->next->head = false;
			//(*lst) = (*lst)->next;
			(*lst)->head = true;
			break ;
		}
	}
	ft_printf("rra\n");
	//print_list(*lst);
}
