/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:53:01 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 16:03:19 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_rb_min_max_value(t_list *ptr, t_list **stack_b, int rb)
{
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
	return (rb);
}

int	determine_rb_number(t_list **stack_b, int value)
{
	int		rb;
	t_list	*ptr;
	int		last_value;

	ptr = *stack_b;
	rb = 0;
	last_value = *(int *)(ft_lstlast(*stack_b)->content);
	if ((*(int *)ptr->content < value) && (last_value > value))
		rb = 0;
	else
	{
		while (ptr && ptr->next)
		{
			rb++;
			if ((*(int *)ptr->content > value)
				&& (*(int *)ptr->next->content < value))
				break ;
			ptr = ptr->next;
		}
	}
	rb = determine_rb_min_max_value(ptr, stack_b, rb);
	return (rb);
}

void	push_cheapest(t_list **stack_a, t_list **stack_b, int index, int value)
{
	int		rb;

	rb = determine_rb_number(stack_b, value);
	rotate_stacks(stack_a, stack_b, index, rb);
	push(stack_b, stack_a, 'b');
}
