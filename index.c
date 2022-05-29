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

static int	get_min(t_list *lst);
static void	assign(t_list *lst, int num, int index);
static void	assign_min(t_list *lst);

void	_index(t_list *lst)
{
	int		i;
	int		min;

	i = 0;
	assign_min(lst);
	min = get_min(lst);
	while (i < lstsize(lst))
	{
		assign(lst, min, i);
		min = get_min(lst);
		i++;
	}
}

static void	assign(t_list *lst, int num, int index)
{
	while (lst)
	{
		if (lst->num == num)
			lst->index = index;
		lst = lst->next;
		if (lst->head == true)
			break ;
	} 
}

static void	assign_min(t_list *lst)
{
	while (lst)
	{
		lst->index = -1;
		lst = lst->next;
		if (lst->head == true)
			break ;
	} 
}

static int	get_min(t_list *lst)
{
	int		min;
	t_list	*tmp;

	min = INT_MAX;
	tmp = lst;
	while (tmp)
	{
		if (min > tmp->num && tmp->index == -1)
			min = tmp->num;
		tmp = tmp->next;
		if (tmp->head == true)
			break ;
	}
	return (min);
}
