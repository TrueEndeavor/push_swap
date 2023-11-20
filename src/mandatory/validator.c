/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:55 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/07 11:10:55 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* compareIgnoringPlus:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
static int	compare_ignoring_plus(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	return (ft_strcmp(s1, s2));
}

/* isDuplicate:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
int	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && compare_ignoring_plus(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Checks 

- Get length of current argument
- If first character and only characer of the argument is just a sign
  return failure
- If first character is not a digit
  return failure
- If any character after the first is not a digit
  return failure (move to the next character)
*/
int	is_not_number(char *input_value)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(input_value);
	i = 1;
	dprintf(1, "len=%zu\n", len);
	dprintf(1, "input_value=%s\n", input_value);
	if ((input_value[0] == '+' || input_value[0] == '-'))
	{
		if (len == 1)
			return (1);
	}
	else if (!ft_isdigit(input_value[0]))
		return (1);
	while (i < len)
	{
		dprintf(1, "checking digit = input_value[%ld] ... ft_isdigit(input_value[%hhd]= %d)\n", i, input_value[i], ft_isdigit(input_value[i]));
		if (!ft_isdigit(input_value[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_overflow(char *input_value)
{
	long	tmp;
	int		len;

	len = ft_strlen(input_value);
	if (len > 11)
		return (1);
	tmp = ft_atol(input_value);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (1);
	return (0);
}
