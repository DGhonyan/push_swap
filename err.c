#include "push_swap.h"

void	err(char *msg, char **arr, char *s)
{
	perror(msg);
	if (arr)
		free_ptr_arr(arr);
	free(s);
	exit (EXIT_FAILURE);
}

void	err_lst(char *msg, char **arr, char *s, t_list *lst)
{
	perror(msg);
	if (arr)
		free_ptr_arr(arr);
	if (lst)
		free_list(lst);
	free(s);
	exit (EXIT_FAILURE);
}