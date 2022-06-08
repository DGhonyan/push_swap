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

void	exit_success(t_list *lst, t_list *b)
{
	while (lst)
	{
		if (!lst->next->head && lst->num > lst->next->num)
			return ;
		lst = lst->next;
		if (lst->head)
			break ;
	}
	if (lstsize(b) == 0)
	{
		free_list(lst);
		exit (EXIT_SUCCESS);
	}
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

void	mark_to_move(t_list *lst)
{
	while (lst)
	{
		lst->next->move = false;
		lst = lst->next;
		if (lst->head)
			break ;
	}
	while (lst)
	{
		if (!lst->next->head && lst->index - lst->next->index != -1)
			lst->next->move = true;
		lst = lst->next;
		if (lst->head)
			break ;
	}
}

int	have_to_move(t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (lst->move)
			return (1); 
		lst = lst->next;
		if (lst->head)
			break ;
	}
	return (0);
}

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
		if (swapped(lst) > non_swapped(lst))
		{
			swap(&lst);
			_index(lst);
			mark_to_move(lst);
			ft_printf(GREEN "sa\n");
			print_list(lst);
		}
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
			_index(lst);
			ft_printf(GREEN "ra\n" RESET);
			print_list(lst);
		}
		//exit_success(lst, b);
	}
	ft_printf("\n");
	while (b)
	{
		ft_printf("%d %d\n", b->num, b->index);
		b = b->next;
	}
	return (0);
}

char * sum(char *s)
{
	return (s);
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
	int i = lstsize(lst);
	largest_sequence(lst);
}
