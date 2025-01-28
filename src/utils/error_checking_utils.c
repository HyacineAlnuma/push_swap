/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:20:16 by halnuma           #+#    #+#             */
/*   Updated: 2025/01/28 10:18:05 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_list **stack_a, t_list **stack_b)
{
	int		value;
	t_list	*ptr;
	t_list	*ptr2;

	ptr = *stack_a;
	while (ptr)
	{
		if (ptr->next)
		{
			ptr2 = ptr->next;
			value = *(int *)ptr->content;
			while (ptr2)
			{
				if (*(int *)ptr2->content == value)
				{
					free_stacks(stack_a, stack_b);
					ft_putstr_fd("Error\n", 2);
					exit(EXIT_FAILURE);
				}
				ptr2 = ptr2->next;
			}
		}
		ptr = ptr->next;
	}
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	check_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '-')
		return (2);
	return (0);
}

int	check_number(char *number)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (number[i])
	{
		if (!check_digit(number[i]))
			return (0);
		else if (check_digit(number[i]) == 2 && sign)
			return (0);
		else if (check_digit(number[i]) == 2 && !sign)
			sign = 1;
		i++;
	}
	if (i > 12)
		return (0);
	if (ft_atoll(number) > INT_MAX || ft_atoll(number) < INT_MIN)
		return (0);
	return (1);
}
