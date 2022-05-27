/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:32:23 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/27 20:30:33 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*allocate_list(char **argv, char *s)
{
	t_list	*list;
	char	*tmp;

	if (s)
		list = s_alloc(s);
	else
		list = argv_alloc(s);
	if (!list)
	{
		ft_printf(RED "Can't allocate list" RESET);
		free(s);
		exit (EXIT_FAILURE);
	}
	return (list);
}

