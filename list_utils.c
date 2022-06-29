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

void	push_b(t_list *lst, t_list **lst_b)
{
	t_list	*new;

	if (!(*lst_b))
	{
		printf("B WAS NULL");
		(*lst_b) = lstnew(lst->num, lst->index, NULL);
		printf("%d\n", (*lst_b)->num);
		if (!(*lst_b))
			err_lst("malloc failed lol", NULL, NULL, lst);
		(*lst_b)->next = (*lst_b);
		(*lst_b)->head = 1;
		return ;
	}
	new = lstnew(lst->num, lst->index, NULL);
	if (!new)
		err_only_lst("malloc failed lol 2", lst, (*lst_b));
	lstlast((*lst_b))->next = new;
	new->next = (*lst_b);
}

void	lstdel(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || lstsize(*lst) == 1)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next;
	while ((tmp)->next)
	{
		tmp = (tmp)->next;
		if (tmp->next->head)
		{
			free(tmp->next);
			tmp->next = NULL;
			break ;
		}
	}
	tmp2->head = true;
	tmp->next = tmp2;
	*lst = tmp2;
}

void	print_list(t_list *lst)
{
	ft_printf("\n");
	while (lst)
	{
		ft_printf("%d %d\n", lst->num, lst->index);
		lst = lst->next;
		if (lst->head)
			break ;
	}
	ft_printf("\n");
}

int	is_sorted(t_list *lst, t_list *b)
{
	while (lst)
	{
		if (!lst->next->head && lst->num > lst->next->num)
			return (0);
		lst = lst->next;
		if (lst->head)
			break ;
	}
	if (lstsize(b) == 0)
	{
		free_list(lst);
		exit (EXIT_SUCCESS);
	}
	return (lstsize(b) == 0);
}
