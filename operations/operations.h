/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/04/03 10:02:37 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "../push_swap.h"
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define TOTAL 11

void	sa(t_stack **a, t_config *cfg);
void	sb(t_stack **b, t_config *cfg);
void	ss(t_stack **a, t_stack **b, t_config *cfg);

void	pa(t_stack **a, t_stack **b, t_config *cfg);
void	pb(t_stack **a, t_stack **b, t_config *cfg);

void	ra(t_stack **a, t_config *cfg);
void	rb(t_stack **b, t_config *cfg);
void	rr(t_stack **a, t_stack **b, t_config *cfg);

void	rra(t_stack **a, t_config *cfg);
void	rrb(t_stack **b, t_config *cfg);
void	rrr(t_stack **a, t_stack **b, t_config *cfg);
#endif
