/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:04:14 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/27 20:47:32 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*argv_alloc(char **argv)
{
	int		i;
	int		j;
	char	**nums;
	t_list	*list;
	t_list	*temp;

	list = lstnew(ft_atoi(*nums), 0, NULL);
	if (!list)
		err("Can't allocate the list", nums, argv);
	temp = list;
	while (argv[i])
	{
		nums = ft_split(argv[i], ' ');
		if (!nums)
			err_list("malloc failed at s_alloc", nums, NULL, list);

		

		free_ptr_arr(nums);
		i++;
	}

}

static void	argv_alloc_util(char **arg)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = lstnew(ft_atoi())
	while (arg[i])
	{

	}
}