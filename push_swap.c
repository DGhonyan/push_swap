#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*s;
	t_list	*list;

	s = NULL;
	if (argc == 1)
		s = get_next_line_new(STDIN_FILENO);
	else
		s = sewing_machine(argv);
	if (!s)
	{
		ft_printf(RED "AAAAAAA" RESET);
		exit (EXIT_FAILURE);
	}
	check_args(argc, argv, s);
	list = allocate_list(s);
	// while (list->next)
	// {
	// 	ft_printf(YELLOW "%d\n" RESET, list->num);
	// 	list = list->next;
	// }
	// while (list)
	// {
	// 	ft_printf(YELLOW "%d\n" RESET, list->num);
	// 	list = list->prev;
	// }
	_index(list);
}