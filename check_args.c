#include "push_swap.h"

static int	is_a_number(char **arg);
static int	check_quotes(char *s, int dbl, int sngl);
static void	ft_printf_exit(char *msg, char *s, char **arr);

void	check_args(int argc, char **argv, char *s)
{
	int		i;
	char	*tmp;
	char	**arg;

	i = 1;
	if (s)
		i = argc - 1;
	check_quotes(s, 0, 0);
	while (i < argc)
	{
		if (s)
			tmp = s;
		else
			tmp = argv[i];
		arg = ft_split(tmp, ' ');
		if (!arg)
			ft_printf_exit("failed to split argv", s, NULL);
		if (!is_a_number(arg))
			ft_printf_exit("YOU BITCH", s, arg);
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

static int	check_quotes(char *s, int dbl, int sngl)
{
	int	i;
	int	double_;
	int	single_;

	i = 0;
	double_ = 0;
	single_ = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\'')
			single_++;
		else if (s[i] == '"')
			double_++;
		if (s[i] == '\'' || s[i] == '"')
			s[i] = ' ';
		i++;
	}
	if (double_ % 2 != 0 || single_ % 2 != 0)
		ft_printf_exit("WRONG QUOTES SHITHEAD", s, NULL);
	return (1);
}

static void	ft_printf_exit(char *msg, char *s, char **arr)
{
	ft_printf(RED "%s\n" RESET, msg);
	if (arr)
		free_ptr_arr(arr);
	free(s);
	exit (EXIT_FAILURE);
}
