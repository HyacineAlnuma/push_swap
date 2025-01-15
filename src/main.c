/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:16:15 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/15 16:34:43 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	split_args(char *args, t_list **stack_a)
{
	char **splited;
	int		i;
	int		*value;


	i = 0;
	splited = ft_split(args, ' ');
	while (splited[i])
	{
		//ft_printf("%s\n", splited[i]);
		value = (int *)malloc(sizeof(int));
		*value = ft_atoi(splited[i]);
		ft_lstadd_back(stack_a, ft_lstnew(value));
		i++;
	}
	//return (stack_a);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;
	int		*value;

	i = 1;
	stack_a = (t_list **)ft_calloc(1, sizeof(t_list *));
	stack_b = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (ac == 2)
	{
		split_args(av[1], stack_a);
		//print_stack(stack_a);
	}
	else if (ac > 2)
	{
		while (av[i])
		{
			value = (int *)malloc(sizeof(int));
			*value = ft_atoi(av[i]);
			ft_lstadd_back(stack_a, ft_lstnew(value));
			i++;
		}
		//i--;
		// while (i > 0)
		// {
		// 	value = (int *)malloc(sizeof(int));
		// 	*value = ft_atoi(av[i]);
		// 	ft_lstadd_back(stack_b, ft_lstnew(value));
		// 	i--;
		// }
	}
	//print_stack(stack_a);
	push_swap(stack_a, stack_b);
	//print_stack(stack_a);
	// ft_printf("//////\n");
	// print_stack(stack_b);
	//free_stacks(stack_a, stack_b);
	return (0);
}
