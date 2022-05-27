#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*s;

	s = NULL;
	if (argc == 1)
		s = get_next_line_new(STDIN_FILENO);
	check_args(argc, argv, s);
	if (!s)
		s = sewing_machine(argv);
	if (!s)
	{
		perror("sewing machine failed");
		exit (EXIT_FAILURE);
	}
}