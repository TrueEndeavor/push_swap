/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:34 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/07 11:10:34 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_duplicate(t_list *stack_a, int value_to_check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content == value_to_check)
			exit (EXIT_SUCCESS);
		stack_a = stack_a->next;
	}
	return ;
}

void	check_sorted(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content > tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	exit(0);
}

void	create_and_add_to_list(t_list **stack_a, int ac, char **av, int index)
{
	t_list *tmp;
	int     value;

	tmp = NULL;
	dprintf(1, "...ac=%d\n", ac);
	dprintf(1, "...index=%d\n", index);	
	while (index < ac)
	{	
		value = ft_atoi_push_swap(av[index]);
		tmp = ft_lstnew(value);
		ft_lstadd_back(stack_a, tmp);
		check_duplicate(*stack_a, tmp->content);
		index++;
	}
	check_sorted(stack_a);
	//ft_lst_inverted(stack_a);
	tmp = NULL;
}
