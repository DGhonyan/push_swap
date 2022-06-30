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

	(void) prev;
	new = malloc(sizeof (*new));
	if (!new)
		return (NULL);
	new->index = index;
	new->num = num;
	new->move = 0;
	new->head = 0;
	new->next = NULL;
	return (new);
}

int	lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	if (!lst)
		return (0);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
		if (!tmp || tmp->head == true)
			break ;
	}
	return (i);
}

void	swap(t_list **lst)
{
	t_list	tmp;

	tmp.num = (*lst)->num;
	tmp.index = (*lst)->index;
	(*lst)->num = (*lst)->next->num;
	(*lst)->index = (*lst)->next->index;
	(*lst)->next->num = tmp.num;
	(*lst)->next->index = tmp.index;
}

void	free_list(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = lstsize(lst);
	while (i--)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
