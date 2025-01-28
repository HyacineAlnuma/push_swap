/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_managing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:22:45 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/28 09:40:04 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack(t_list **stack, char **values)
{
	int	*i_value;
	int	i;

	i = 1;
	while (values[i])
	{
		if (!check_number(values[i]))
			return (0);
		i_value = (int *)malloc(sizeof(int));
		if (!i_value)
			return (0);
		*i_value = ft_atoi(values[i]);
		ft_lstadd_back(stack, ft_lstnew(i_value));
		i++;
	}
	return (1);
}

int	fill_stack_from_split(t_list **stack, char **splited)
{
	int		i;
	int		*value;

	i = 0;
	while (splited[i])
	{
		if (!check_number(splited[i]))
		{
			ft_free_split(splited);
			return (0);
		}
		value = (int *)malloc(sizeof(int));
		if (!value)
		{
			ft_free_split(splited);
			return (0);
		}
		*value = ft_atoi(splited[i]);
		ft_lstadd_back(stack, ft_lstnew(value));
		i++;
	}
	return (1);
}

int	split_args(char *args, t_list **stack_a)
{
	char	**splited;

	splited = ft_split(args, ' ');
	if (!splited)
		return (0);
	if (!fill_stack_from_split(stack_a, splited))
		return (0);
	ft_free_split(splited);
	return (1);
}
