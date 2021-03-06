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

int	norminette(t_list **lst)
{
	if (!lst)
		return (0);
	if (lstsize(*lst) == 1)
	{
		free(*lst);
		*lst = NULL;
		return (0);
	}
	return (1);
}

void	push_b(t_list *lst, t_list **lst_b, int lol)
{
	t_list	*new;

	if (!(*lst_b))
	{
		(*lst_b) = lstnew(lst->num, -1, NULL);
		if (!(*lst_b))
			err_lst("malloc failed lol", NULL, NULL, lst);
		(*lst_b)->next = (*lst_b);
		(*lst_b)->head = 1;
		return ;
	}
	new = lstnew(lst->num, -1, NULL);
	if (!new)
		err_only_lst("malloc failed lol 2", lst, (*lst_b));
	new->head = 1;
	lstlast(*lst_b)->next = new;
	(*lst_b)->head = 0;
	new->next = (*lst_b);
	(*lst_b) = new;
	if (lol)
		ft_printf("pa\n");
}

void	lstdel(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!norminette(lst))
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
	if (!lst)
		return ;
	ft_printf("\n");
	while (1)
	{
		ft_printf("%d %d %d %d\n", lst->num, lst->index, lst->move, lst->spot);
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
