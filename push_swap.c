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

void	more_norm(t_list **lst, void (**rotate)(t_list **, int))
{
	*rotate = &rra;
	if (aaaaaaah(*lst).index < lstsize(*lst) / 2)
		*rotate = &lstrotate;
	while (!((*lst)->head && (*lst)->num == aaaaaaah(*lst).num))
		(*rotate)(lst, 0);
}

void	fill_b(t_list *lst, int size)
{
	t_list	*b;
	void	(*rotate)(t_list **, int);

	b = NULL;
	rotate = &rra;
	more_norm(&lst, &rotate);
	mark_to_move(lst);
	while (have_to_move(lst))
	{
		is_sorted(lst, b);
		if (is_sorted_break(lst))
			break ;
		if (swapped(lst) > non_swapped(lst))
		{
			list_swap(&lst);
		}
		else if (lst->head && lst->move)
			pb(&lst, &b);
		else
			lstrotate(&lst, 0);
	}
	is_sorted(lst, b);
	sort_a(lst, b);
}

void	help(t_move *min_moves, t_move moves, int *min)
{
	if (*min > move_count(moves))
	{
		*min = move_count(moves);
		*min_moves = moves;
	}
}

void	sort_a(t_list *a, t_list *b)
{
	int		min;
	int		size;
	t_move	moves;
	t_move	min_moves;

	size = lstsize(b);
	while (lstsize(b))
	{
		spot(a, b);
		min = INT_MAX;
		assign_moves(&min_moves);
		while (1)
		{
			moves = calculate(a, b, size);
			if (min > move_count(moves))
				help(&min_moves, moves, &min);
			b = b->next;
			if (b->head)
				break ;
		}
		do_the_thing(min_moves, &a, &b);
	}
	while (!is_sorted_break(a))
		lstrotate(&a, 0);
	free_list(a);
}

int	main(int argc, char **argv)
{
	char	*s;
	t_list	*lst;

	s = NULL;
	if (argc == 1)
		return (0);
	s = sewing_machine(argv);
	if (!s)
	{
		ft_printf(RED "malloc failed, earth will\
			be destroyed in a minute\n" RESET);
		exit(EXIT_FAILURE);
	}
	check_args(argc, s);
	lst = allocate_list(s);
	free(s);
	_index(lst);
	fill_b(lst, lstsize(lst));
}
