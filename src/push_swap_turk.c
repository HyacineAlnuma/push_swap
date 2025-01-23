/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:51:46 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/23 13:31:25 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// int	calculate_cost(t_list **stack_a, t_list** stack_b, int pos_a, int value)
// {
// 	int		cost;
// 	int		rotate;
// 	int		size_a;
// 	int		size_b;
// 	t_list	*ptr;

// 	size_a = ft_lstsize(*stack_a);
// 	size_b = ft_lstsize(*stack_b);
// 	if (pos_a >= size_a / 2)
// 		cost = 100 - pos_a;
// 	else
// 		cost = pos_a;
// 	ptr = *stack_b;
// 	rotate = 0;
// 	while (ptr && ptr->next)
// 	{
// 		rotate++;
// 		if ((*(int *)ptr->content > value) && (*(int *)ptr->next->content < value))
// 			break ;
// 		ptr = ptr->next;
// 	}
// 	if (rotate >= size_b / 2)
// 		cost += 100 - rotate;
// 	else
// 		cost += rotate;
// 	return (cost);
// }

int	calculate_cost(t_list **stack_a, t_list** stack_b, int pos_a, int value)
{
	int		cost;
	int		pos_b;
	int		size_a;
	int		size_b;
	int		last_value;
	t_list	*ptr;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (pos_a >= size_a / 2)
		cost = size_a - pos_a;
	else
		cost = pos_a;
	ptr = *stack_b;
	last_value = *(int *)(ft_lstlast(*stack_b)->content);
	pos_b = 0;
	if ((*(int *)ptr->content < value) && (last_value > value))
			pos_b = 0;
	else
	{
		while (ptr && ptr->next)
		{
			pos_b++;
			if ((*(int *)ptr->content > value) && (*(int *)ptr->next->content < value))
				break ;
			ptr = ptr->next;
		}
	}
	if (!(ptr->next))
	{
		pos_b = 0;
		ptr = *stack_b;
		while (ptr && ptr->next)
		{
			pos_b++;
			if (*(int *)ptr->content < *(int *)ptr->next->content)
				break ;
			ptr = ptr->next;
		}
		if (!(ptr->next))
			pos_b = 0;
	}
	if (pos_b > size_b / 2)
		cost += (size_b - pos_b);
	else
		cost += pos_b;
	return (cost);
}

int	find_cheapest(t_list **stack_a, t_list** stack_b)
{
	t_list	*ptr;
	int		i;
	int		smallest_cost;
	int		current_cost;
	int		value;
	int		pos_a;

	ptr = *stack_a;
	i = 0;
	smallest_cost = 10000;
	while (ptr)
	{
		value = *(int *)ptr->content;
		current_cost = calculate_cost(stack_a, stack_b, i, value);
		if (current_cost < smallest_cost)
		{
			smallest_cost = current_cost;
			pos_a = i;
		}
		i++;
		ptr = ptr->next;
	}
	//ft_printf("cost: %d\n", smallest_cost);
	return (pos_a);
}

void	push_cheapest(t_list **stack_a, t_list **stack_b, int pos_a, int value)
{
	int		size_a;
	int		size_b;
	int		rb;
	//int		value;
	int		last_value;
	t_list	*ptr;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	ptr = *stack_b;
	// if (pos_a <= size_a / 2)
	// {
	// 	while (pos_a > 0)
	// 	{
	// 		rotate(stack_a);
	// 		ft_printf("ra\n");
	// 		pos_a--;
	// 	}
	// }
	// else
	// {
	// 	while (pos_a < size_a)
	// 	{
	// 		reverse_rotate(stack_a);
	// 		ft_printf("rra\n");
	// 		pos_a++;
	// 	}
	// }
	rb = 0;
	//value = *(int *)(*stack_a)->content;
	last_value = *(int *)(ft_lstlast(*stack_b)->content);
	if ((*(int *)ptr->content < value) && (last_value > value))
			rb = 0;
	else
	{
		while (ptr && ptr->next)
		{
			rb++;
			if ((*(int *)ptr->content > value) && (*(int *)ptr->next->content < value))
				break ;
			ptr = ptr->next;
		}
	}
	if (!(ptr->next))
	{
		rb = 0;
		ptr = *stack_b;
		while (ptr && ptr->next)
		{
			rb++;
			if (*(int *)ptr->content < *(int *)ptr->next->content)
				break ;
			ptr = ptr->next;
		}
		if (!(ptr->next))
			rb = 0;
	}


	if ((pos_a <= size_a / 2) && (rb <= size_b / 2))
	{
		while ((rb > 0) && (pos_a > 0))
		{
			rotate(stack_b);
			rotate(stack_a);
			ft_printf("rr\n");
			rb--;
			pos_a--;
		}
		while (pos_a > 0)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			pos_a--;
		}
		while (rb > 0)
		{
			rotate(stack_b);
			ft_printf("rb\n");
			rb--;
		}
	}
	else if ((pos_a > size_a / 2) && (rb > size_b / 2))
	{
		while ((rb < size_b) && (pos_a < size_a))
		{
			reverse_rotate(stack_b);
			reverse_rotate(stack_a);
			ft_printf("rrr\n");
			rb++;
			pos_a++;
		}
		while (pos_a < size_a)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			pos_a++;
		}
		while (rb < size_b)
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
			rb++;
		}
	}
	else if ((pos_a <= size_a / 2) && (rb > size_b / 2))
	{
		while (pos_a > 0)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			pos_a--;
		}
		while (rb < size_b)
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
			rb++;
		}
	}
	else if ((pos_a > size_a / 2) && (rb <= size_b / 2))
	{
		while (pos_a < size_a)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			pos_a++;
		}
		while (rb > 0)
		{
			rotate(stack_b);
			ft_printf("rb\n");
			rb--;
		}
	}
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

void sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	third = *(int *)(*stack)->next->next->content;
	if (first > second && second > third)
	{
		rotate(stack);
		ft_printf("ra\n");
		swap(stack);
		ft_printf("sa\n");
	}
	else if (first < second && second > third)
	{
		if (first < third)
		{
			swap(stack);
			ft_printf("sa\n");
			rotate(stack);
			ft_printf("ra\n");
		}
		else
		{
			reverse_rotate(stack);
			ft_printf("rra\n");
		}
	}
	else if (first > second && second < third)
	{
		if (first < third)
		{
			swap(stack);
			ft_printf("sa\n");
		}
		else
		{
			rotate(stack);
			ft_printf("ra\n");
		}
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		pos_a;
	t_list	*ptr;
	int		smallest;
	int		smallest_index;
	int		i;
	int		value;
	//int		last_value;

	size_a = ft_lstsize(*stack_a);
	if (size_a == 3)
	{
		sort_three(stack_a);
		return ;
	}
	push(stack_b, stack_a);
	ft_printf("pb\n");
	push(stack_b, stack_a);
	ft_printf("pb\n");
	if (*(int *)(*stack_b)->content > *(int *)(*stack_b)->next->content)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	while (*stack_a)
	{
		pos_a = find_cheapest(stack_a, stack_b);
		//ft_printf("cheapest: %dth\n", pos_a);
		ptr = *stack_a;
		i = 0;
		while (i <= pos_a)
		{
			if (i == pos_a)
				value = *(int *)ptr->content;
			ptr = ptr->next;
			i++;
		}
		push_cheapest(stack_a, stack_b, pos_a, value);
	}



	//sort_three(stack_a);
	while (*stack_b)
	{
		// last_value = *(int *)(ft_lstlast(*stack_a))->content;
		// if (last_value > *(int *)(*stack_b)->content && last_value < *(int *)(*stack_a)->content)
		// {
		// 	reverse_rotate(stack_a);
		// 	ft_printf("rra\n");
		// }
		push(stack_a, stack_b);
		ft_printf("pa\n");
	}
	i = 0;
	smallest = *(int *)(*stack_a)->content;
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
	if (smallest_index <= (size_a / 2))
	{
		while (i < smallest_index)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			i++;
		}
	}
	else
	{
		i = size_a;
		while (i > smallest_index)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			i--;
		}
	}
}
