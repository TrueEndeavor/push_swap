/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:54:22 by lannur-s          #+#    #+#             */
/*   Updated: 2024/01/23 16:55:37 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	*tmp;
	int		first;
	int		second;
	int		third;

	tmp = NULL;
	first = 0;
	second = 0;
	third = 0;
	tmp = *stack_a;
	first = tmp->content;
	tmp = tmp->next;
	second = tmp->content;
	tmp = tmp->next;
	third = tmp->content;
	if ((first > second && second < third && third > first) \
		|| (first > second && second > third && third < first) \
		|| (first < second && second > third && third > first))
		swap_a(stack_a);
	else if (first > second && second < third && third < first)
		rotate_a(stack_a);
	else if (first < second && second > third && third < first)
		reverse_rotate_a(stack_a);
}
