#include "push_swap.h"

static int	get_min(t_list *lst);
static void	assign(t_list *lst, int num, int index);

void	_index(t_list *lst)
{
	int		i;
	int		min;

	i = 0;
	min = get_min(lst);
	ft_printf("%d\n", lstsize(lst));
	while (i < lstsize(lst))
	{
		ft_printf("##%d\n", min);
		assign(lst, min, i);
		min = get_min(lst);
		i++;
	}

	while (lst)
	{
		//if (lst->num == min)
		ft_printf(GREEN "%d %d\n" RESET, lst->index, lst->num);
		//	lst->index = i++;
		lst = lst->next;
	}
}

static void	assign(t_list *lst, int num, int index)
{
	while (lst->next)
	{
		if (lst->num == num)
			lst->index = index;
		lst = lst->next;
	}
	if (lst->num == num)
		lst->index = index;
	while (lst->prev)
		lst = lst->prev;
}

static int	get_min(t_list *lst)
{
	int		min;
	t_list	*tmp;

	min = INT_MAX;
	tmp = lst;
	while (tmp)
	{
		if (min > tmp->num && tmp->index == -1)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}