/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_managing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:22:45 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/27 15:30:39 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_args(char *args, t_list **stack_a)
{
	char	**splited;
	int		i;
	int		*value;

	i = 0;
	splited = ft_split(args, ' ');
	if (!splited)
		return (0);
	while (splited[i])
	{
		value = (int *)malloc(sizeof(int));
		if (!value || !check_number(splited[i]))
		{
			ft_free_split(splited);
			return (0);
		}
		*value = ft_atoi(splited[i]);
		ft_lstadd_back(stack_a, ft_lstnew(value));
		i++;
	}
	ft_free_split(splited);
	return (1);
}

int	fill_stack(t_list **stack, char **values)
{
	int	*i_value;
	int	i;

	i = 1;
	while (values[i])
	{
		i_value = (int *)malloc(sizeof(int));
		if (!i_value || !check_number(values[i]))
			return (0);
		*i_value = ft_atoi(values[i]);
		ft_lstadd_back(stack, ft_lstnew(i_value));
		i++;
	}
	return (1);
}
