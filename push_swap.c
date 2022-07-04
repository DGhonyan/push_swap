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
	//print_list(lst);
	mark_to_move(lst);
	// spot(lst, b);
	//print_list(lst);
	while (have_to_move(lst))
	{
		is_sorted(lst, b);
		if (is_sorted_break(lst))
			break ;
		if (swapped(lst) > non_swapped(lst))
		{
			print_list(lst);
			list_swap(&lst);
		}
		else if (lst->head && lst->move)
			pb(&lst, &b);
		else
			lstrotate(&lst, 0);
	}
	is_sorted(lst, b);
	print_list(lst);
	print_list(b);
	sort_a(lst, b);
}

void	sort_a(t_list *a, t_list *b)
{
	int		min;
	int		max;
	void	(*rotate)(t_list **, int);

	assign_min(a);
	assign_min(b);
	print_list(b);
	min = INT_MAX;
	//calculate(a, b);
	int i = lstsize(b);
	while (i--)
	{
		if (min > calculate(a, b));
			min = calculate(a, b);
		b = b->next;
		if (b->head)
			break ;
	}
	printf("%d\n", min);
	//t_move m = calculate(a, b);
	//printf("%d %d %d %d", m.ra, m.rb, m.rra, m.rrb, m.pb);
	// while (!(b->head && b->num == get_min(b)))
	// 	lstrotate(&b, 1);
	//calculate(*a, *b);
	// while (lstsize(b))
	// {
	// 	min = 0;
	// 	max = 0;
	// 	rotate = &rra;
		// if (choose_rotate(a, b) < lstsize(a) / 2)
	// 		rotate = &lstrotate;
	// 	while (!(b->num > a->num && b->num < a->next->num))
	// 	{
	// 		if (b->num < get_min(a) && (a->head && a->num == get_min(a)))
	// 		{
	// 			min = 1;
	// 			break ;
	// 		}
	// 		else if (b->num > get_max(a) && (a->head && a->num == get_min(a)))
	// 		{
	// 			max = 1;
	// 			break ;
	// 		}
	// 		rotate(&a,0);
	// 	}
	// 	push_b(b, &a, 1);
	// 	lstdel(&b);
	// 	if (max)
	// 		rra(&a, 0);
	// 	else if (!min && !max)
	// 		swap(&a);
	// 	// }
	// }
	// while (!is_sorted_break(a))
	// {
	// 	lstrotate(&a, 0);
	// }
	// print_list(a);
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
