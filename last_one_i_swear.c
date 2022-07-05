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

int	choose_rotate(t_list *a, t_list *b)
{
	int	i;
	int	where;

	where = -1;
	i = 0;
	printf(" HOLA BITCH %d", b->num);
	while (1)
	{
		if (b->num > a->num && b->num < a->next->num)
			where = i;
		a = a->next;
		if (a->head)
			break ;
		i++;
	}
	return (where);
}

int	_max(t_list *a)
{
	int	min;
	int	i;
	int	where;

	where = -1;
	i = 0;
	min = get_min(a);
	while (1)
	{
		if (a->num == min)
			where = i;
		a = a->next;
		if (a->head)
			break ;
		i++;
	}
	return (where);
}

int	is_sorted_break(t_list *lst)
{
	while (lst)
	{
		if (!lst->next->head && lst->num > lst->next->num)
			return (0);
		lst = lst->next;
		if (lst->head)
			break ;
	}
	return (1);
}

t_what	aaaaaaah(t_list *list)
{
	int		i;
	int		j;
	int		max;
	t_list	*lst;
	t_what	aaah;

	j = 0;
	aaah.num = 0;
	aaah.index = 0;
	max = INT_MIN;
	lst = list;
	i = lstsize(list);
	while (i--)
	{
		if (hello(lst) > max)
		{
			aaah.index = j;
			aaah.num = lst->num;
			max = hello(lst);
		}
		lstrotate_check(&lst);
		j++;
	}
	return (aaah);
}

int	hello(t_list *tmp)
{
	int	i;
	int	head;

	i = 0;
	head = tmp->index;
	tmp = tmp->next;
	while (1)
	{
		if ((tmp->index - head == 1))
		{
			head = tmp->index;
			i++;
		}
		tmp = tmp->next;
		if (tmp->head)
			break ;
	}
	return (i);
}
