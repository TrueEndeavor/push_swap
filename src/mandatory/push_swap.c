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
	int		index;
	char	**arg;
	char    *endptr;

	size = 0;
	index = 0;
	arg = NULL;
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		while (arg[size] != NULL)
			size++;
		dprintf(1, "Try 1: arg[%d] %ld\n", index, ft_strtol(arg[index], &endptr, 10));
		if (arg[index] != NULL && (ft_strtol(arg[index], &endptr, 10)))
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_SUCCESS);
		}
		if (arg[index] != NULL)
			create_and_add_to_list(stack_a, index, av, 0);
		index++;
	}
	while (ac >= 3)
	{
	dprintf(1, "Try 1: >3: av[%d] %s\n", index, av[index]);	
		if (is_not_number(av[index]) || is_overflow(av[index]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_SUCCESS);
		}
		create_and_add_to_list(stack_a, index, av, 1);
		index--;
	}
}

void	create_and_add_to_list(t_list **stack_a, int size, char **av, int i)
{
	t_list	*tmp;

	tmp = NULL;
	(void) av;
	while (i < size)
	{
		//tmp = ft_lstnew((void *)ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		//ft_lstcheck(*stack_a, tmp->content);
		i++;
	}
	//ft_lst_order(stack_a);
	//ft_lst_inverted(stack_a);
	tmp = NULL;
	
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	//t_list	*stack_b;

	stack_a = NULL;
	//stack_b = NULL;
	if (ac == 1)
		exit (EXIT_SUCCESS);
	else
		initialize_stack_a(&stack_a, ac, av);
	exit (EXIT_SUCCESS);
	//list_of_input = load_ps_data(ac, av);
	//print_ps_data(list_of_input);
	//int n = sizeof(12) / sizeof(t_ps_data);
	//lis(av, n);
	return (0);
}
