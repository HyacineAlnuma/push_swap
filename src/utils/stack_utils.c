/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:14:19 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 14:11:04 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*ptr;
	int		*value;

	if (!(*stack))
		return ;
	ptr = *stack;
	while (ptr)
	{
		value = ptr->content;
		ft_printf("%d\n", *value);
		ptr = ptr->next;
	}
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		ft_lstclear(stack_a, NULL);
	if (*stack_b)
		ft_lstclear(stack_b, NULL);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}

int	find_smallest_index(t_list **stack)
{
	int		smallest;
	t_list	*ptr;
	int		smallest_index;
	int		i;

	smallest = *(int *)(*stack)->content;
	smallest_index = 0;
	ptr = *stack;
	i = 0;
	while (ptr)
	{
		if (*(int *)ptr->content < smallest)
		{
			smallest = *(int *)ptr->content;
			smallest_index = i;
		}
		ptr = ptr->next;
		i++;
	}
	return (smallest_index);
}

int	is_sorted(t_list **stack)
{
	int		previous;
	t_list	*ptr;

	if (!(*stack) || !(*stack)->next)
		return (0);
	previous = *(int *)(*stack)->content;
	ptr = *stack;
	if (ptr->next)
		ptr = ptr->next;
	while (ptr)
	{
		if (*(int *)ptr->content < previous)
			return (0);
		previous = *(int *)ptr->content;
		ptr = ptr->next;
	}
	return (1);
}

void	order_stack(t_list **stack)
{
	int		smallest_index;
	int		i;
	int		stack_size;

	stack_size = ft_lstsize(*stack);
	i = 0;
	smallest_index = find_smallest_index(stack);
	if (smallest_index <= (stack_size / 2))
	{
		while (i < smallest_index)
		{
			rotate(stack, 'a');
			i++;
		}
	}
	else
	{
		i = stack_size;
		while (i > smallest_index)
		{
			reverse_rotate(stack, 'a');
			i--;
		}
	}
}
