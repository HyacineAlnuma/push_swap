/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:51:46 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/10 14:34:00 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	find_smallest(t_list **stack_a, t_list **stack_b, int count)
{
	int		smallest;
	int		biggest;
	t_list	*ptr;
	int		i;
	int		smallest_index;
	int		biggest_index;
	int		stack_size;
	int		s_to_e;
	int		b_to_e;

	smallest = *(int *)(*stack_a)->content;
	biggest = *(int *)(*stack_a)->content;
	ptr = *stack_a;
	stack_size = ft_lstsize(*stack_a);
	i = 0;
	biggest_index = 0;
	smallest_index = 0;
	(void)stack_b;
	while (ptr)
	{
		if (*(int *)ptr->content < smallest)
		{
			smallest = *(int *)ptr->content;
			smallest_index = i;
		}
		else if (*(int *)ptr->content > biggest)
		{
			biggest = *(int *)ptr->content;
			biggest_index = i;
		}
		ptr = ptr->next;
		i++;
	}
	i = 0;
	s_to_e = stack_size - smallest_index;
	b_to_e = stack_size - biggest_index;
	if (smallest_index <= biggest_index && smallest_index <= s_to_e && smallest_index <= b_to_e)
	{
		while (i < smallest_index)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			count++;
			i++;
		}
		push(stack_b, stack_a);
		ft_printf("pb\n");
		count++;
	}
	else if (biggest_index < smallest_index && biggest_index <= s_to_e && smallest_index <= b_to_e)
	{
		while (i < biggest_index)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			count++;
			i++;
		}
		push(stack_b, stack_a);
		ft_printf("pb\n");
		count++;
		rotate(stack_b);
		ft_printf("rb\n");
		count++;
	}
	else if (s_to_e < biggest_index && s_to_e < smallest_index && s_to_e <= b_to_e)
	{
		i = stack_size;
		while (i > smallest_index)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			count++;
			i--;
		}
		push(stack_b, stack_a);
		ft_printf("pb\n");
		count++;
	}
	else if (b_to_e < biggest_index && b_to_e < smallest_index && b_to_e < s_to_e)
	{
		i = stack_size;
		while (i > biggest_index)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			count++;
			i--;
		}
		push(stack_b, stack_a);
		ft_printf("pb\n");
		count++;
		rotate(stack_b);
		ft_printf("rb\n");
		count++;
	}
	return (count);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	count;
	int		smallest;
	t_list	*ptr;
	int		i;
	int		smallest_index;
	int		stack_size;

	count = 0;
	count = find_smallest(stack_a, stack_b, count);
	while (*stack_a)
		count = find_smallest(stack_a, stack_b, count);
	while (*stack_b)
	{
		push(stack_a, stack_b);
		ft_printf("pa\n");
		count++;
	}
	i = 0;
	smallest = *(int *)(*stack_a)->content;
	stack_size = ft_lstsize(*stack_a);
	ptr = *stack_a;
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
	i = 0;
	if (smallest_index <= (stack_size / 2))
	{
		while (i < smallest_index)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			count++;
			i++;
		}
	}
	else
	{
		i = stack_size;
		while (i > smallest_index)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			count++;
			i--;
		}
	}
	ft_printf("Intstruction counter: %d\n", count);
}
