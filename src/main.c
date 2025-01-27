/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:16:15 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 15:48:05 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;

	stack_a = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (!stack_a)
		return (0);
	if (ac == 2)
	{
		if (!split_args(av[1], stack_a))
		{
			ft_putstr_fd("Error", 2);
			free_stacks(stack_a, NULL);
			return (0);
		}
	}
	else if (ac > 2)
	{
		if (!fill_stack(stack_a, av))
		{
			ft_putstr_fd("Error", 2);
			free_stacks(stack_a, NULL);
			return (0);
		}
	}
	push_swap(stack_a);
	return (0);
}

void	push_swap(t_list **stack_a)
{
	int		stack_size;
	t_list	**stack_b;

	stack_b = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (!stack_b)
	{
		free_stacks(stack_a, NULL);
		ft_putstr_fd("Error", 2);
		return ;
	}
	check_duplicates(stack_a);
	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 1 || stack_size == 0 || is_sorted(stack_a))
	{
		free_stacks(stack_a, stack_b);
		return ;
	}
	else
		sort_stack(stack_a, stack_b, stack_size);
	free_stacks(stack_a, stack_b);
}
