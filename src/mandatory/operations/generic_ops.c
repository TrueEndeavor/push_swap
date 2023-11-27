/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:23:09 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/27 19:39:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
	return ;
}

void	push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (*dest == NULL)
		return ;
	tmp = *dest;
	*dest = (*dest)->next;
	tmp->next = *src;
	*src = tmp;
	return ;
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	first = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack;
	tmp = *stack;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	tmp->next = NULL;
	return ;
}

