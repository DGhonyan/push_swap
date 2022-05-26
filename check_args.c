#include "push_swap.h"

static int	is_a_number(char **arg);

void	check_args(int argc, char **argv)
{
	int		i;
	char	**arg;

	i = 1;
	while (i < argc)
	{
		arg = ft_split(argv[i], ' ');
		if (!arg)
		{
			ft_printf(RED "failed to split argv\n" RESET);
			exit (EXIT_FAILURE);
		}
		if (!is_a_number(arg))
			ft_printf(RED "YOU BITCH %d\n" RESET, i);
		free_ptr_arr(arg);
		i++;
	}
}

static int	is_a_number(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
