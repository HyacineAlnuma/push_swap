/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:51:46 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/23 09:30:15 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		value;
	int		i;
	int		j;
	int		lst_size_a;
	int		rb;
	int		k;
	//int		lst_size_b;

	lst_size_a = ft_lstsize(*stack_a);
	i = 0;
	k = 0;
	while (i < 32  && !is_sorted(stack_a))
	{
		j = 0;
		rb = 0;
		while (j < lst_size_a)
		{
			value = *(int *)(*stack_a)->content;
			if (!(value & (1 << i)))
			{
				k = rb;
				while (k > 0)
				{
					rotate(stack_b);
					ft_printf("rb\n");
					k--;
				}
				push(stack_b, stack_a);
				ft_printf("pb\n");
				k = rb;
				while (k > 0)
				{
					reverse_rotate(stack_b);
					ft_printf("rrb\n");
					k--;
				}
				rb++;
			}
			else
			{
				push(stack_b, stack_a);
				ft_printf("pb\n");
				rotate(stack_b);
				ft_printf("rb\n");
			}
			j++;
		}
		i++;
		rb = 0;
		j = 0;
		while (j < lst_size_a)
		{
			value = *(int *)(*stack_b)->content;
			if (!(value & (1 << i)))
			{
				k = rb;
				while (k > 0)
				{
					rotate(stack_a);
					ft_printf("ra\n");
					k--;
				}
				push(stack_a, stack_b);
				ft_printf("pa\n");
				k = rb;
				while (k > 0)
				{
					reverse_rotate(stack_a);
					ft_printf("rra\n");
					k--;
				}
				rb++;
			}
			else
			{
				push(stack_a, stack_b);
				ft_printf("pa\n");
				rotate(stack_a);
				ft_printf("ra\n");
			}
			j++;
		}
		// while (*stack_b)
		// {
		// 	push(stack_a, stack_b);
		// 	ft_printf("pa\n");
		// }
		i++;
	}
}
