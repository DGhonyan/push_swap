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
	int	i;

	i = 0;
	i = moves.pb + moves.ra + moves.rb
		+ moves.rra + moves.rrb + moves.sa;
	return (i);
}

void	print_moves(t_move moves)
{
	printf("%d %d %d %d %d\n", moves.rb, moves.rrb, moves.ra, moves.rra, moves.sa);
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
	print_list(lst);
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
	int		num;
	int		size;
	int		i;
	t_move	moves;
	t_move	min_moves;
	void	(*rotate)(t_list **, int);

	assign_min(a);
	assign_min(b);
	spot(a, b);
	// print_list(a);

	size = lstsize(b);
	i = size;
	// while (i--)
	// {
	// 	moves = calculate(a, b, size);
	// 	printf("%d ", b->num);
	// 	print_moves(moves);
	// 	b = b->next;
	// }
	while (lstsize(b))
	{
		spot(a, b);
		min = INT_MAX;
		// assign_moves(&min_moves);
		i = lstsize(b);
		// min_moves = calculate(a, b, size);
		while (i)
		{
			moves = calculate(a, b, size);
			if (min > move_count(moves))
			{
				num = b->num;
				min = move_count(moves);
				min_moves = moves;
			}
			b = b->next;
			if (b->head)
				break ;
		}
		assign_min(a);
		do_the_thing(min_moves, &a, &b);
		// print_list(a);
		// print_list(b);
		// lstdel(&b);
	}
	// print_list(a);
	// print_list(b);
	
	// while (!is_sorted_break(a))
	// {
	// 	lstrotate(&a, 0);
	// }
	print_list(a);
	free_list(a);
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
}
