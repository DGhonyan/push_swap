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

int	_max(t_list *a, t_list *b)
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
