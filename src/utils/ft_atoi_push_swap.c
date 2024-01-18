/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:34 by marvin            #+#    #+#             */
/*   Updated: 2024/01/11 15:11:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v');
}

int	ft_atoi_push_swap(const char *str)
{
	long res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isnumber((char *) str))
	{
		write(1, "Error. Input is not a number\n", 30);
		exit (EXIT_FAILURE);
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (res > INT_MAX || res < INT_MIN)
	{
	write(1, "Error. Integer overflow\n", 24);
	exit (EXIT_FAILURE);
	}
	return (res * sign);
}
