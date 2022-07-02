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

void fill_b(t_list *lst)
{
	t_list *b;
	void	(*rotate)(t_list **);

	b = NULL;
	rotate = &rra;
	if (aaaaaaah(lst).index < lstsize(lst) / 2)
		rotate = &lstrotate;
	while (!(lst->head && lst->num == aaaaaaah(lst).num))
		rotate(&lst);
	mark_to_move(lst);
	while (have_to_move(lst))
	{
		is_sorted(lst, b);
		if (is_sorted_break(lst))
			break;
		if (swapped(lst) > non_swapped(lst))
			list_swap(&lst);
		else if (lst->head && lst->move)
			pb(&lst, &b);
		else
			lstrotate(&lst);
	}
	is_sorted(lst, b);
	// print_list(lst);
	// print_list(b);
	sort_a(lst, b);
}

void find_the_spot(t_list *lst, int num)
{
	t_list *tmp;
}

void sort_a(t_list *a, t_list *b)
{
	int	min;
	int	max;
	void (*rotate)(t_list **);

	assign_min(a);
	while (lstsize(b))
	{
		min = 0;
		max = 0;
		// if (b->num < get_min(a) && (a->head && a->num == get_min(a)))
		// {
		// 	// rotate = &rra;
		// 	// if (_max(a, b) < lstsize(a) / 2)
		// 	// 	rotate = &lstrotate;
		// 	// while (!(a->head && a->num == get_min(a)))
		// 	// 	rotate(&a);
		// 	push_b(b, &a, 1);
		// 	lstdel(&b);
		// }
		// else if (b->num > get_max(a) && (a->head && a->num == get_min(a)))
		// {
		// 	// rotate = &rra;
		// 	// if (_max(a, b) < lstsize(a) / 2)
		// 	// 	rotate = &lstrotate;
		// 	// while (!(a->head && a->num == get_min(a)))
		// 	// 	rotate(&a);
		// 	push_b(b, &a, 1);
		// 	lstdel(&b);
		// 	rra(&a);
		// }
		// else
		// {
		rotate = &rra;
		if (choose_rotate(a, b) < lstsize(a) / 2)
			rotate = &lstrotate;
		while (!(b->num > a->num && b->num < a->next->num))
		{
			if (b->num < get_min(a) && (a->head && a->num == get_min(a)))
			{
				min = 1;
				break ;
			}
			else if (b->num > get_max(a) && (a->head && a->num == get_min(a)))
			{
				max = 1;
				break ;
			}
			rotate(&a);
		}
		push_b(b, &a, 1);
		lstdel(&b);
		if (max)
			rra(&a);
		else if (!min && !max)
			swap(&a);
		// }
	}
	while (!is_sorted_break(a))
	{
		//printf("A");
		lstrotate(&a);
	}
	// print_list(a);
	free_list(a);
}

int main(int argc, char **argv)
{
	char *s;
	t_list *lst;

	s = NULL;
	if (argc == 1)
		return (0);
		//s = get_next_line_new(STDIN_FILENO);
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
