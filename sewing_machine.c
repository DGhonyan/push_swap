/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sewing_machine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:09:24 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/27 21:26:48 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*sewing_utils(char *s, char *s2);

char	*sewing_machine(char **argv)
{
	int		i;
	char	*s;

	i = 2;
	s = ft_strjoin(argv[1], " ");
	if (!s)
		return (NULL);
	while (argv[i])
	{
		s = sewing_utils(s, argv[i]);
		if (!s)
			return (NULL);
		i++;
	}
	ft_printf(MAGENTA "%s\n" RESET, s);
	return (s);
}
static char	*sewing_utils(char *s, char *s2)
{
	int		i;
	char	*res;

	res = malloc(sizeof (*res) * (ft_strlen(s) + ft_strlen(s2) + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = ' ';
	res[i + 1] = '\0';
	return (res);
}