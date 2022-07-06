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

int	move_count(t_move moves)
{
	return (moves.pb + moves.ra + moves.rb
		+ moves.rra + moves.rrb + moves.sa + moves.rra_end);
}

void	print_moves(t_move moves)
{
	printf("rb %d rrb %d ra %d rra %d sa %d ra_end %d\n", moves.rb, moves.rrb, moves.ra, moves.rra, moves.sa, moves.rra_end);
}

void	fill_b(t_list *lst)
{
	t_list	*b;
	void	(*rotate)(t_list **, int);

	b = NULL;
	rotate = &rra;
	if (aaaaaaah(lst).index < lstsize(lst) / 2)
		rotate = &lstrotate;
	while (!(lst->head && lst->num == aaaaaaah(lst).num))
		rotate(&lst, 0);
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
	// print_list(lst);
	// print_list(b);
	sort_a(lst, b);
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
			{
				min = move_count(moves);
				min_moves = moves;
			}
			b = b->next;
			if (b->head)
				break ;
		}
		do_the_thing(min_moves, &a, &b);
	}
}

//s = get_next_line_new(STDIN_FILENO);
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
	fill_b(lst);
	while (!is_sorted_break(lst))
		lstrotate(&lst, 0);
	free_list(lst);
}
