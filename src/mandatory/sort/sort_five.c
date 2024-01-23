/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:08:37 by marvin            #+#    #+#             */
/*   Updated: 2024/01/11 21:08:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 2;
	while (i-- > 0)
		push(stack_a, stack_b);
	sort_three(stack_a);
	//ft_move_to_a(stack_a, stack_b);
	//ft_search_min(stack_a, ft_lstsize(*stack_a));
}

void	ft_move_to_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	/* while (*stack_b != NULL)
	{
		i = ft_best_nbr_b(stack_b, size_b, stack_a, size_a);
		if (i < 0)
			while (i++ < 0)
				reverse_rotate(stack_b);
		else if (i > 0)
			while (i-- > 0)
				rotate(stack_b);
		push(stack_b, stack_a);
		size_a++;
		size_b--;
	}
}

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max)
{
	int	i;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	i = ft_best_nbr_a(*stack_a, size_a, arr, max);
	while (i != -1)
	{
		if (i > 0)
		{
			while (i-- > 0)
				rotate(stack_a);
		}
		push(stack_a, stack_b);
		//i = ft_best_nbr_a(*stack_a, --size_a, arr, max);
	} */
}
