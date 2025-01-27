/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:50:50 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 16:03:10 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sub_rs_one(t_list **stack_a, t_list **stack_b, int index, int rb)
{
	while ((rb > 0) && (index > 0))
	{
		rotate(stack_b, 'r');
		rotate(stack_a, 'r');
		ft_printf("rr\n");
		rb--;
		index--;
	}
	while (index > 0)
	{
		rotate(stack_a, 'a');
		index--;
	}
	while (rb > 0)
	{
		rotate(stack_b, 'b');
		rb--;
	}
}

void	sub_rs_two(t_list **stack_a, t_list **stack_b, int index, int rb)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while ((rb < size_b) && (index < size_a))
	{
		reverse_rotate(stack_b, 'r');
		reverse_rotate(stack_a, 'r');
		ft_printf("rrr\n");
		rb++;
		index++;
	}
	while (index < size_a)
	{
		reverse_rotate(stack_a, 'a');
		index++;
	}
	while (rb < size_b)
	{
		reverse_rotate(stack_b, 'b');
		rb++;
	}
}

void	sub_rs_three(t_list **stack_a, t_list **stack_b, int index, int rb)
{
	int		size_b;

	size_b = ft_lstsize(*stack_b);
	while (index > 0)
	{
		rotate(stack_a, 'a');
		index--;
	}
	while (rb < size_b)
	{
		reverse_rotate(stack_b, 'b');
		rb++;
	}
}

void	sub_rs_four(t_list **stack_a, t_list **stack_b, int index, int rb)
{
	int		size_a;

	size_a = ft_lstsize(*stack_a);
	while (index < size_a)
	{
		reverse_rotate(stack_a, 'a');
		index++;
	}
	while (rb > 0)
	{
		rotate(stack_b, 'b');
		rb--;
	}
}

void	rotate_stacks(t_list **stack_a, t_list **stack_b, int index, int rb)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if ((index <= size_a / 2) && (rb <= size_b / 2))
		sub_rs_one(stack_a, stack_b, index, rb);
	else if ((index > size_a / 2) && (rb > size_b / 2))
		sub_rs_two(stack_a, stack_b, index, rb);
	else if ((index <= size_a / 2) && (rb > size_b / 2))
		sub_rs_three(stack_a, stack_b, index, rb);
	else if ((index > size_a / 2) && (rb <= size_b / 2))
		sub_rs_four(stack_a, stack_b, index, rb);
}
