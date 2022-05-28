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

t_list	*lstnew(int num, int index, t_list *prev)
{
	t_list	*new;

	new = malloc(sizeof (*new));
	if (!new)
		return (NULL);
	new->index = index;
	new->num = num;
	new->move = false;
	new->head = false;
	new->next = NULL;
	new->prev = prev;
	return (new);
}
