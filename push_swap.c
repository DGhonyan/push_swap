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

void	rotate(t_list *(*lst));

int	main(int argc, char **argv)
{
	char	*s;
	t_list	(*lst);

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
	int i = lstsize(lst);
	while (i--)
	{
		while (lst)
		{
			ft_printf(CYAN "%d %d %d\n", lst->num, lst->index, lst->head);
			lst = lst->next;
			if (lst->head == true)
				break ;
		}
		ft_printf("\n\n");
		a(&lst);
	}
}

void	rotate(t_list **lst)
{
	while (*lst)
	{
		*lst = (*lst)->next;
		if ((*lst)->head == true)
		{
			(*lst)->head = false;
			(*lst) = (*lst)->next;
			(*lst)->head = true;
			break ;
		}
	}
}
