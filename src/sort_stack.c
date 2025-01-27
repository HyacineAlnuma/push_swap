/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:51:48 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 16:03:24 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_b(t_list **stack_a, t_list **stack_b)
{
	int		cheapest_index;
	t_list	*ptr;
	int		value;
	int		i;

	if (*(int *)(*stack_b)->content > *(int *)(*stack_b)->next->content)
		rotate(stack_b, 'b');
	while (*stack_a)
	{
		cheapest_index = find_cheapest(stack_a, stack_b);
		ptr = *stack_a;
		i = 0;
		while (i <= cheapest_index)
		{
			if (i == cheapest_index)
				value = *(int *)ptr->content;
			ptr = ptr->next;
			i++;
		}
		push_cheapest(stack_a, stack_b, cheapest_index, value);
	}
}

void	sort_big_stack(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, 'b');
	push(stack_b, stack_a, 'b');
	fill_stack_b(stack_a, stack_b);
	while (*stack_b)
		push(stack_a, stack_b, 'a');
	order_stack(stack_a);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2)
		sort_two(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
}
