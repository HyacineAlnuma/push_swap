/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:51:46 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/23 13:31:47 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		value;
	int		i;
	int		j;
	int		lst_size_a;

	lst_size_a = ft_lstsize(*stack_a);
	i = 0;
	while (i < 32  && !is_sorted(stack_a))
	{
		j = 0;
		while (j < lst_size_a && !is_sorted(stack_a))
		{
			value = *(int *)(*stack_a)->content;
			if (!(value & (1 << i)))
			{
				push(stack_b, stack_a);
				ft_printf("pb\n");
			}
			else
			{
				rotate(stack_a);
				ft_printf("ra\n");
			}
			j++;
		}
		while (*stack_b)
		{
			push(stack_a, stack_b);
			ft_printf("pa\n");
		}
		i++;
	}
}
