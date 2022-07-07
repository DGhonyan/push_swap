/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:27:53 by dghonyan          #+#    #+#             */
/*   Updated: 2022/07/07 18:27:56 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_count(t_move moves)
{
	return (moves.pb + moves.ra + moves.rb
		+ moves.rra + moves.rrb + moves.sa + moves.rra_end);
}
