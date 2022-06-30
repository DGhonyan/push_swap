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
	ft_printf(GREEN "sa\n" RESET);
	print_list(*lst);
}

void	pb(t_list **lst, t_list **b)
{
	push_b(*lst, b);
	lstdel(lst);
	_index(*lst);
	mark_to_move(*lst);
	ft_printf(GREEN "pb\n" RESET);
	print_list(*lst);
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
	ft_printf(GREEN "ra\n" RESET);
	print_list(*lst);
}
