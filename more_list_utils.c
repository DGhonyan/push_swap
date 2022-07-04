/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:27:17 by dghonyan          #+#    #+#             */
/*   Updated: 2022/06/22 11:27:18 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swapped(t_list *lst)
{
	int		sequence;
	int		head;

	swap(&lst);
	head = lst->index;
	lst = lst->next;
	sequence = 0;
	while (lst)
	{
		if (!lst->index - head == 1)
			sequence++;
		lst = lst->next;
		if (lst->head)
			break ;
	}
	swap(&lst);
	return (sequence);
}

int	non_swapped(t_list *lst)
{
	int		sequence;
	int		head;

	sequence = 0;
	head = lst->index;
	lst = lst->next;
	while (lst)
	{
		if (!lst->next->head && lst->index - lst->next->index == -1)
			sequence++;
		lst = lst->next;
		if (lst->head)
			break ;
	}
	return (sequence);
}

void	mark_to_move(t_list *lst)
{
	int	head;

	while (lst)
	{
		lst->next->move = false;
		lst = lst->next;
		if (lst->head)
			break ;
	}
	head = lst->index;
	lst = lst->next;
	while (lst)
	{
		if (lst->index - head == 1)
			head = lst->index;
		else
			lst->move = 1;
		lst = lst->next;
		if (lst->head)
			break ;
	}
	//print_list(lst);
}

int	have_to_move(t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (lst->move)
			return (1);
		lst = lst->next;
		if (lst->head)
			break ;
	}
	return (0);
}

t_list	*lstlast(t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		lst = lst->next;
		if (lst->next->head)
			return (lst);
	}
	return (NULL);
}
