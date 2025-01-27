/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:16:27 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 13:26:54 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	int	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	push(t_list **a, t_list **b, char c)
{
	t_list	*first_a;
	t_list	*first_b;

	if (!(*b))
		return ;
	first_a = *b;
	first_b = first_a->next;
	*b = first_b;
	ft_lstadd_front(a, first_a);
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rotate(t_list **stack, char c)
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
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **stack, char c)
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
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
