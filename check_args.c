/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:28:49 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/27 19:31:46 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_a_number(char **arg);
static int	check_quotes(char *s, int dbl, int sngl);
static int	dupes(char **arg);
static void	ft_printf_exit(char *msg, char *s, char **arr);

void	check_args(int argc, char *s)
{
	char	**arg;

	check_quotes(s, 0, 0);
	arg = ft_split(s, ' ');
	if (!arg)
		ft_printf_exit("failed to split argv", s, NULL);
	if (!is_a_number(arg))
		ft_printf_exit("Wrong arguments", s, arg);
	if (!dupes(arg))
		ft_printf_exit("Duplicate arguments", s, arg);
	free_ptr_arr(arg);
}

static int	is_a_number(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		if ((arg[i][0] == '-' && ft_strlen(arg[i]) == 1)
			|| (ft_atoi(arg[i]) > INT_MAX || ft_atoi(arg[i]) < INT_MIN))
			return (0);
		j = arg[i][0] == '-';
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
	else if (double_ + single_ == ft_strlen(s))
		ft_printf_exit("You can't do that", s, NULL);
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

static int	dupes(char **arg)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	arr = malloc(ptr_arr_len(arg) * sizeof (*arr));
	while (arg[i])
	{
		arr[i] = ft_atoi(arg[i]);
		i++;
	}
	i = 0;
	while (arg[i])
	{
		j = i;
		while (arg[j])
		{
			if (arr[i] == arr[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	free(arr);
	return (1);
}
