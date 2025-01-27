/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:48 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 15:53:09 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a_cost(t_list **stack_a, int index)
{
	int		size_a;
	int		cost;

	size_a = ft_lstsize(*stack_a);
	if (index >= size_a / 2)
		cost = size_a - index;
	else
		cost = index;
	return (cost);
}

int	rotate_b_cost(t_list **stack_b, int pos_b, t_list *ptr)
{
	int		size_b;
	int		cost;

	size_b = ft_lstsize(*stack_b);
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
		cost = (size_b - pos_b);
	else
		cost = pos_b;
	return (cost);
}

int	calc_cost(t_list **stack_a, t_list **stack_b, int index, int value)
{
	int		cost;
	int		pos_b;
	t_list	*ptr;
	int		last_value;

	cost = rotate_a_cost(stack_a, index);
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
			if ((*(int *)ptr->content > value)
				&& (*(int *)ptr->next->content < value))
				break ;
			ptr = ptr->next;
		}
	}
	cost += rotate_b_cost(stack_b, pos_b, ptr);
	return (cost);
}

int	find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		i;
	int		cost[2];
	int		value;
	int		cheapest_index;

	ptr = *stack_a;
	i = 0;
	cost[0] = INT_MAX;
	while (ptr)
	{
		value = *(int *)ptr->content;
		cost[1] = calc_cost(stack_a, stack_b, i, value);
		if (cost[1] < cost[0])
		{
			cost[0] = cost[1];
			cheapest_index = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (cheapest_index);
}
