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

int	swapped(t_list *lst)
{
	int		sequence;
	t_list	tmp;

	swap(&lst);
	sequence = 0;
	while (lst)
	{
		if (!lst->next->head && lst->index - lst->next->index == -1)
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
	t_list	tmp;

	sequence = 0;
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

int	to_move(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (lst->move)
			return (1);
		tmp = tmp->next;
		if (tmp->head)
			break ;
	}
	return (0);
}

int	largest_sequence(t_list *lst)
{
	int		i;
	t_seq	*sequence;

	i = lstsize(lst);
	sequence = malloc(sizeof (*sequence) * i);
	while (i--)
	{
		sequence[i].seq = 0;
		if (swapped(lst) > non_swapped(lst))
		{
			swap(&lst);
			ft_printf(GREEN "sa\n" RESET);
		}
		sequence[i].num = lst->num;
		while (lst)
		{
			if (!lst->next->head && lst->index - lst->next->index == -1)
			{
				sequence[i].seq += 1;
			}
			else if (!lst->next->head && lst->index - lst->next->index != -1)
				lst->move = true;
			ft_printf("%d %d %d\n", lst->move, lst->num, lst->index);
			lst = lst->next;
			if (lst->head)
				break ;
		}

		ft_printf("\n\n");
		ft_printf("%d\n", to_move(lst));
		ft_printf("\n\n");
		lstrotate(&lst);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	int		i;
	char	*s;
	t_list	*lst;

	s = NULL;
	if (argc == 1)
		s = get_next_line_new(STDIN_FILENO);
	else
		s = sewing_machine(argv);
	if (!s)
	{
		ft_printf(RED "malloc failed, earth will\
			be destroyed in a minute\n" RESET);
		exit (EXIT_FAILURE);
	}
	check_args(argc, s);
	lst = allocate_list(s);
	_index(lst);
	largest_sequence(lst);
	// ft_printf("%d\n", lst->num);
	// swapped(lst);
	// ft_printf("%d\n", lst->num);
}
