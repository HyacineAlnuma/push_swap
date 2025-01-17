/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:16:27 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/17 11:41:44 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap(t_list **stack)
{
	int	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	push(t_list **a, t_list **b)
{
	t_list	*first_a;
	t_list	*first_b;

	if (!(*b))
		return ;
	first_a = *b;
	first_b = first_a->next;
	*b = first_b;
	ft_lstadd_front(a, first_a);
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	first = (*stack)->next;
	last = *stack;
	ft_lstadd_back(stack, last);
	last->next = NULL;
	*stack = first;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second;
	t_list	*i;

	if (!(*stack) || !((*stack)->next))
		return ;
	last = ft_lstlast(*stack);
	second = *stack;
	ft_lstadd_front(stack, last);
	last->next = second;
	i = *stack;
	while (i)
	{
		if (i->next == last)
			i->next = NULL;
		i = i->next;
	}
}