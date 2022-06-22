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

int	largest_sequence(t_list *lst)
{
	int		i;
	t_list	*b;
	t_seq	*sequence;

	i = lstsize(lst);
	b = NULL;
	mark_to_move(lst);
	while (have_to_move(lst))
	{
		ft_printf("\n");
		is_sorted(lst, b);
		if (swapped(lst) > non_swapped(lst))
			list_swap(lst, b);
		else if (lst->head && lst->move)
		{
			b = push_b(lst, b);
			lstdel(&lst);
			_index(lst);
			ft_printf(GREEN "pb\n" RESET);
			print_list(lst);
		}
		else
		{
			lstrotate(&lst);
			ft_printf(GREEN "ra\n" RESET);
			print_list(lst);
			is_sorted(lst, b);
		}
	}
	ft_printf("\n");
	while (b)
	{
		ft_printf("%d %d\n", b->num, b->index);
		b = b->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
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
	free(s);
	_index(lst);
	largest_sequence(lst);
}
