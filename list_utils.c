#include "push_swap.h"

t_list	*push_b(t_list *lst, t_list *lst_b)
{
	t_list	*new;

	new = lstnew(lst->num, lst->index, NULL);
	if (!new)
	{
		ft_printf(RED "malloc failed at push_b" RESET);
		free_list(lst);
		free_list(lst_b);
	}
	if (lst_b)
		new->next = lst_b;
	return (new);
}