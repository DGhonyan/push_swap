/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:04:14 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/27 20:04:39 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*s_alloc(char *s)
{
	int		i;
	char	**nums;
	t_list	*list;
	t_list	*temp;

	nums = ft_split(s, ' ');
	if (!nums)
		err("malloc failed at s_alloc", NULL, s);
	list = lstnew(ft_atoi(*nums), 0, NULL);
	if (!list)
		err("Can't allocate the list", nums, s);
	temp = list;
	nums++;
	while (*nums)
	{
		list->next = lstnew(ft_atoi(*nums), 0, list);
		if (!list->next)
			err_list("malloc failed at s_alloc", nums, s, list);
		list = list->next;
		nums++;
	}
	free_ptr_arr(nums);
	return (list);
}