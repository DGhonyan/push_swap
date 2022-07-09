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

t_list	*allocate_list(char *s)
{
	int		i;
	char	**nums;
	t_list	*list;
	t_list	*temp;

	nums = ft_split(s, ' ');
	if (!nums)
		err("malloc failed at s_alloc", NULL, s);
	list = lstnew(ft_atoi(nums[0]), -1, NULL);
	list->head = true;
	if (!list)
		err("Can't allocate the list", nums, s);
	temp = list;
	i = 1;
	while (nums[i])
	{
		list->next = lstnew(ft_atoi(nums[i]), -1, list);
		if (!list->next)
			err_lst("malloc failed at alloc", nums, s, list);
		list = list->next;
		i++;
	}
	list->next = temp;
	free_ptr_arr(nums);
	return (temp);
}
