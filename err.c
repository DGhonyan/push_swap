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

void	err(char *msg, char **arr, char *s)
{
	ft_printf(RED "%s\n" RESET, msg);
	free_ptr_arr(arr);
	free(s);
	exit (EXIT_FAILURE);
}

void	err_lst(char *msg, char **arr, char *s, t_list *lst)
{
	ft_printf(RED "%s\n" RESET, msg);
	if (arr)
		free_ptr_arr(arr);
	if (lst)
		free_list(lst);
	free(s);
	exit (EXIT_FAILURE);
}
