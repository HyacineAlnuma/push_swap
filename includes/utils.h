/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:23:21 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 14:08:30 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

// ----- ARGS_MANAGING ----- //

int			split_args(char *args, t_list **stack_a);
int			fill_stack(t_list **stack, char **values);

// ----- ERROR_CHECKING ----- //

void		check_duplicates(t_list **stack);
long long	ft_atoll(const char *nptr);
int			check_digit(int c);
int			check_number(char *number);

// ----- INSTRUCTIONS ----- //

void		reverse_rotate(t_list **list, char c);
void		rotate(t_list **list, char c);
void		push(t_list **a, t_list **b, char c);
void		swap(t_list **list, char c);

// ----- STACK_UTILS ----- //

void		print_stack(t_list **stack);
void		free_stacks(t_list **stack_a, t_list **stack_b);
int			find_smallest_index(t_list **stack);
int			is_sorted(t_list **stack);
void		order_stack(t_list **stack);

#endif