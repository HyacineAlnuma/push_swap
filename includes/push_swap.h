/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:16:50 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/17 09:42:01 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void	reverse_rotate(t_list **list);
void	rotate(t_list **list);
void	push(t_list **a, t_list **b);
void	swap(t_list **list);
void	print_stack(t_list **stack);
void	free_stacks(t_list **stack_a, t_list **stack_b);
void	push_swap(t_list **stack_a, t_list **stack_b);

#endif