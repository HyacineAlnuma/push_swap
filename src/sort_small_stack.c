/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:18:12 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 15:46:06 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_two(t_list **stack)
{
	int	count;

	count = 0;
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
	{
		rotate(stack, 'a');
		count++;
	}
	return (count);
}

void	sub_sort_three(t_list **stack, int first, int second, int third)
{
	if (first < second && second > third)
	{
		if (first < third)
		{
			swap(stack, 'a');
			rotate(stack, 'a');
		}
		else
			reverse_rotate(stack, 'a');
	}
	else if (first > second && second < third)
	{
		if (first < third)
			swap(stack, 'a');
		else
			rotate(stack, 'a');
	}
}

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	third = *(int *)(*stack)->next->next->content;
	if (first > second && second > third)
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
	else
		sub_sort_three(stack, first, second, third);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	smallest_index;

	smallest_index = find_smallest_index(stack_a);
	if (smallest_index == 1)
		rotate(stack_a, 'a');
	else if (smallest_index == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (smallest_index == 3)
		reverse_rotate(stack_a, 'a');
	push(stack_b, stack_a, 'b');
	sort_three(stack_a);
	push(stack_a, stack_b, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	smallest_index;

	smallest_index = find_smallest_index(stack_a);
	if (smallest_index == 1)
		rotate(stack_a, 'a');
	else if (smallest_index == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (smallest_index == 3)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (smallest_index == 4)
		reverse_rotate(stack_a, 'a');
	push(stack_b, stack_a, 'b');
	sort_four(stack_a, stack_b);
	push(stack_a, stack_b, 'a');
}
