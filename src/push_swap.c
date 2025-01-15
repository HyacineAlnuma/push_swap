/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:51:46 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/15 16:28:27 by halnuma          ###   ########.fr       */
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
	int		second_biggest;
	int		second_smallest;
	int		second_smallest_index;
	int		second_biggest_index;
	static int		s_flag = 0;
	static int		b_flag = 0;
	int		stack_size;
	int		s_to_e;
	int		b_to_e;
	int		ss_to_e;
	int		sb_to_e;
	static int	iter = 0;

	smallest = *(int *)(*stack_a)->content;
	biggest = *(int *)(*stack_a)->content;
	ptr = *stack_a;
	stack_size = ft_lstsize(*stack_a);
	i = 0;
	biggest_index = 0;
	smallest_index = 0;
	while (ptr)
	{
		if (*(int *)ptr->content < smallest)
		{
			second_smallest = smallest;
			second_smallest_index = smallest_index;
			smallest = *(int *)ptr->content;
			smallest_index = i;
		}
		else if (*(int *)ptr->content < second_smallest)
		{
			second_smallest = *(int *)ptr->content;
			second_smallest_index = i;
		}
		else if (*(int *)ptr->content > biggest)
		{
			second_biggest = biggest;
			second_biggest_index = biggest_index;
			biggest = *(int *)ptr->content;
			biggest_index = i;
		}
		else if (*(int *)ptr->content > second_biggest)
		{
			second_biggest = *(int *)ptr->content;
			second_biggest_index = i;
		}
		ptr = ptr->next;
		i++;
	}
	i = 0;
	s_to_e = stack_size - smallest_index;
	b_to_e = stack_size - biggest_index;
	sb_to_e = stack_size - second_biggest_index;
	ss_to_e = stack_size - second_smallest_index;

	//ft_printf("smallest: %d biggest: %d smallest_index: %d biggest_index: %d s_to_e: %d b_to_e: %d ss:%d sb: %d ssi: %d sbi:%d sstoe: %d sbtoe: %d\n", smallest, biggest, smallest_index, biggest_index, s_to_e, b_to_e, second_smallest, second_biggest, second_smallest_index, second_biggest_index, ss_to_e, sb_to_e);
	//exit(EXIT_FAILURE);
		
	// if (iter == 14)
	// 	{
	// 		ft_printf("--------------------\n");
	// 		print_stack(stack_a);
	// 		ft_printf("--------------------\n");
	// 		print_stack(stack_b);
	// 		ft_printf("flag: %d\n", s_flag);
	// 		ft_printf("iter: %d\n", iter);
	// 		ft_printf("smallest: %d biggest: %d smallest_index: %d biggest_index: %d s_to_e: %d b_to_e: %d ss:%d sb: %d ssi: %d sbi:%d sstoe: %d sbtoe: %d\n", smallest, biggest, smallest_index, biggest_index, s_to_e, b_to_e, second_smallest, second_biggest, second_smallest_index, second_biggest_index, ss_to_e, sb_to_e);
	// 		ft_printf("--------------------\n");
	// 		exit(EXIT_FAILURE);
	// 	}
	// if (sb_to_e < biggest_index && sb_to_e < s_to_e && sb_to_e <= b_to_e && sb_to_e < smallest_index && sb_to_e < second_smallest_index && sb_to_e < second_biggest_index && sb_to_e < ss_to_e && !b_flag)
	// {
	// 	i = stack_size;
	// 	while (i > biggest_index)
	// 	{
	// 		reverse_rotate(stack_a);
	// 		ft_printf("rra\n");
	// 		count++;
	// 		i--;
	// 	}
	// 	push(stack_b, stack_a);
	// 	ft_printf("pb\n");
	// 	count++;
	// 	rotate(stack_b);
	// 	ft_printf("rb\n");
	// 	count++;
	// 	b_flag = 1;
	// }

	if (second_biggest_index < biggest_index && second_biggest_index < s_to_e && second_biggest_index < b_to_e && second_biggest_index < smallest_index && second_biggest_index < second_smallest_index && !b_flag)
	{
		while (i < second_biggest_index)
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
		b_flag = 1;
	}
	else if (second_smallest_index < biggest_index && second_smallest_index < s_to_e && second_smallest_index < b_to_e && second_smallest_index < smallest_index && !s_flag)
	{
		while (i < second_smallest_index)
		{
			rotate(stack_a);
			ft_printf("raw\n");
			count++;
			i++;
		}
		push(stack_b, stack_a);
		ft_printf("pb\n");
		count++;
		s_flag = 1;
	}

	// else if (ss_to_e < biggest_index && ss_to_e < s_to_e && ss_to_e <= b_to_e && ss_to_e < smallest_index && ss_to_e < second_smallest_index && ss_to_e < second_biggest_index && ss_to_e < sb_to_e && !s_flag)
	// {
	// 	i = stack_size;
	// 	while (i > smallest_index)
	// 	{
	// 		reverse_rotate(stack_a);
	// 		ft_printf("rra\n");
	// 		count++;
	// 		i--;
	// 	}
	// 	push(stack_b, stack_a);
	// 	ft_printf("pb\n");
	// 	count++;
	// 	// 		if (iter == 14)
	// 	// {
	// 	// 	ft_printf("--------------------\n");
	// 	// 	print_stack(stack_a);
	// 	// 	ft_printf("--------------------\n");
	// 	// 	print_stack(stack_b);
	// 	// 	ft_printf("flag: %d\n", s_flag);
	// 	// 	ft_printf("iter: %d\n", iter);
	// 	// 	ft_printf("smallest: %d biggest: %d smallest_index: %d biggest_index: %d s_to_e: %d b_to_e: %d ss:%d sb: %d ssi: %d sbi:%d sstoe: %d sbtoe: %d\n", smallest, biggest, smallest_index, biggest_index, s_to_e, b_to_e, second_smallest, second_biggest, second_smallest_index, second_biggest_index, ss_to_e, sb_to_e);
	// 	// 	ft_printf("--------------------\n");
	// 	// 	exit(EXIT_FAILURE);
	// 	// }
	// 	// rotate(stack_b);
	// 	// ft_printf("rb\n");
	// 	// count++;
	// 	s_flag = 1;
	// }
	else if (smallest_index <= biggest_index && smallest_index <= s_to_e && smallest_index <= b_to_e)
	// if (smallest_index <= biggest_index && smallest_index <= s_to_e && smallest_index <= b_to_e && smallest_index < second_smallest_index && smallest_index < second_biggest_index)
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
		if (s_flag)
		{
			swap(stack_b);
			ft_printf("sb\n");
			count++;
			s_flag = 0;
		}
	}
	else if (biggest_index < smallest_index && biggest_index <= s_to_e)
	// else if (biggest_index < smallest_index && biggest_index <= s_to_e && biggest_index < second_smallest_index && biggest_index < second_biggest_index)
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
		if (b_flag)
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
			count++;
			swap(stack_b);
			ft_printf("sb\n");
			count++;
			rotate(stack_b);
			ft_printf("rb\n");
			count++;
			b_flag = 0;
		}
		rotate(stack_b);
		ft_printf("rb\n");
		count++;
	}
	else if (s_to_e < biggest_index && s_to_e < smallest_index && s_to_e <= b_to_e)
	// else if (s_to_e < biggest_index && s_to_e < smallest_index && s_to_e <= b_to_e && s_to_e < second_smallest_index && s_to_e < second_biggest_index)
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
		if (s_flag)
		{
			swap(stack_b);
			ft_printf("sb\n");
			count++;
			s_flag = 0;
		}
	}
	else if (b_to_e < biggest_index && b_to_e < smallest_index && b_to_e < s_to_e)
	// else if (b_to_e < biggest_index && b_to_e < smallest_index && b_to_e < s_to_e && b_to_e < second_smallest_index && b_to_e < second_biggest_index)
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
		if (b_flag)
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
			count++;
			swap(stack_b);
			ft_printf("sb\n");
			count++;
			rotate(stack_b);
			ft_printf("rb\n");
			count++;
			b_flag = 0;
		}
		rotate(stack_b);
		ft_printf("rb\n");
		count++;
	}
	iter++;
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
	//ft_printf("Intstruction counter: %d\n", count);
}
