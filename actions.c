/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:28:03 by dghonyan          #+#    #+#             */
/*   Updated: 2022/06/22 11:28:05 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_swap(t_list *lst, t_list *b)
{
	swap(&lst);
	_index(lst);
	mark_to_move(lst);
	ft_printf(GREEN "sa\n");
	is_sorted(lst, b);
}