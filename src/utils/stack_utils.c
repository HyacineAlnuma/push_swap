/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:14:19 by halnuma           #+#    #+#             */
/*   Updated: 2024/12/27 15:42:54 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	ft_lstclear(stack_a, NULL);
	ft_lstclear(stack_b, NULL);
	free(stack_a);
	free(stack_b);
}
