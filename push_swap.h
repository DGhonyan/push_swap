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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_what
{
	int	num;
	int	index;
}	t_what;

typedef struct s_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	pb;
	int	sa;
	int	rra_end;
}	t_move;

typedef struct s_list {
	int				move;
	int				head;
	int				num;
	int				index;
	int				spot;
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
int		hello(t_list *lst);
int		get_min_not_weird(t_list *a);
int		get_max_not_weird(t_list *a);
int		lstsize(t_list *lst);
int		is_sorted_break(t_list *lst);
int		is_sorted(t_list *lst, t_list *b);
int		swapped(t_list *lst);
int		non_swapped(t_list *lst);
int		have_to_move(t_list *list);
int		get_min(t_list *lst);
int		get_max(t_list *lst);
int		_max(t_list *a);
int		choose_rotate(t_list *a, t_list *b);
void	mark_to_move(t_list *lst);
void	list_swap(t_list **lst);
void	sort_a(t_list *a, t_list *b);
void	assign_min(t_list *lst);
void	free_list(t_list *lst);
void	_index(t_list *lst);
void	lstdel(t_list **lst);
void	lstrotate(t_list **lst, int b);
void	rra(t_list **lst, int b);
void	lstrotate_check(t_list **lst);
void	swap(t_list **lst);
void	pb(t_list **lst, t_list **b);
void	print_list(t_list *lst);
void	push_b(t_list *lst, t_list **stack_b, int lol);
void	spot(t_list *a, t_list *b);
int		move_count(t_move moves);
void	do_the_thing(t_move moves, t_list **a, t_list **b);
void	assign_moves(t_move *moves);
t_move	calculate(t_list *lst_a, t_list *lst_b, int size);
t_list	*lstlast(t_list *list);
t_list	*allocate_list(char *s);
t_list	*lstnew(int num, int index, t_list *prev);
t_what	aaaaaaah(t_list *list);
//Lists

#endif