/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:11 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/07 11:10:11 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack_a(t_list **stack_a, int ac, char **av)
{
	int		size;
	char	**split_args;

	size = 0;
	split_args = NULL;
	if (ac == 2)
	{
		split_args = ft_split(av[1], ' ');
		if (split_args != NULL)
		{
			while (split_args[size] != NULL)
				size++;
			create_and_add_to_list(stack_a, size, split_args, 0);
			if (split_args != NULL)
				free(split_args);
		}
	}
	else
		create_and_add_to_list(stack_a, ac, av, 1);
}

void	perform_push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	int	*dst;
	int	*arr;
	int	i;

	i = 0;
	if (size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (size == 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	dst = ft_copy_cont(*stack_a, size);
	arr = ft_define_lis(dst, size, &i);
	ft_move_to_b(stack_a, stack_b, arr, i);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, size);
	free (dst);
	free (arr);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	//t_list	*stack_b;
	int		size;

	stack_a = NULL;
	//stack_b = NULL;
	size = 0;
	if (ac == 1)
		exit (EXIT_SUCCESS);
	else
		initialize_stack_a(&stack_a, ac, av);
	size = ft_lstsize(stack_a);
	if (size == 2)
		return (0);
	perform_push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
