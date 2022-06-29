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

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_seq {
	int	num;
	int	seq;
}	t_seq;

typedef struct s_list {
	bool			head;
	bool			move;
	int				num;
	int				spot;
	int				index;
	struct s_list	*next;
}	t_list;

//Args
void	check_args(int argc, char *s);
char	*sewing_machine(char **argv);
//Args

//Errors
void	err(char *msg, char **arr, char *s);
void	err_lst(char *msg, char **arr, char *s, t_list *lst);
void	err_only_lst(char *msg, t_list *lst, t_list *lst_b);
//Errors

//Lists
int		lstsize(t_list *lst);
int		is_sorted(t_list *lst, t_list *b);
int		swapped(t_list *lst);
int		non_swapped(t_list *lst);
int		have_to_move(t_list *list);
void	mark_to_move(t_list *lst);
void	list_swap(t_list **lst);
void	free_list(t_list *lst);
void	_index(t_list *lst);
void	lstdel(t_list **lst);
void	lstrotate(t_list **lst);
void	swap(t_list **lst);
void	pb(t_list **lst, t_list **b);
void	print_list(t_list *lst);
void	push_b(t_list *lst, t_list **stack_b);
t_list	*lstlast(t_list *list);
t_list	*allocate_list(char *s);
t_list	*lstnew(int num, int index, t_list *prev);
//Lists

#endif