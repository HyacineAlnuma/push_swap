/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:16:50 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 16:02:17 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

void	push_swap(t_list **stack_a);
int		calc_cost(t_list **stack_a, t_list **stack_b, int index, int value);
void	push_cheapest(t_list **stack_a, t_list **stack_b, int index, int value);
int		find_cheapest(t_list **stack_a, t_list **stack_b);
void	rotate_stacks(t_list **stack_a, t_list **stack_b, int index, int rb);
void	sort_stack(t_list **stack_a, t_list **stack_b, int stack_size);
int		sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);

#endif