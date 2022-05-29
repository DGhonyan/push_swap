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

void	lstdel(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || lstsize(*lst) == 1)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next;
	while ((tmp)->next)
	{
		tmp = (tmp)->next;
		if (tmp->next->head)
		{
			free(tmp->next);
			tmp->next = NULL;
			break ;
		}
	}
	tmp2->head = true;
	tmp->next = tmp2;
	*lst = tmp2;
}