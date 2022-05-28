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

static t_list	*alloc(char *s);

t_list	*allocate_list(char *s)
{
	t_list	*list;

	list = alloc(s);
	if (!list)
	{
		ft_printf(RED "Can't allocate list" RESET);
		exit (EXIT_FAILURE);
	}
	return (list);
}

// t_list	*allocate_list_b(t_list *lst_a, char *s)
// {
// 	int		i;
// 	t_list	*lst;
// 	t_list	*tmp;

// 	i = 0;
// 	lst = lstnew(0, -1, NULL);
// 	if (!lst)
// 		return (NULL);
// 	tmp = lst;
// 	while (i < lstsize(lst_a))
// 	{
// 		lst->next = lstnew(0, -1, lst);
// 		if (!lst->next)
// 		{
// 			free_list(lst);
// 			return (NULL);
// 		}
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (lst);
// }

static t_list	*alloc(char *s)
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
