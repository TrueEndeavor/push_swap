/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:41 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/07 11:10:41 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void free_ps_data(t_ps_data *data) 
{
    t_node *current = data->head;
    while (current != NULL) {
        t_node *temp = current;
        current = current->next;
        free(temp);
    }

    // Free remaining stack nodes if any
    while (data->stack_a.top != NULL) {
        t_node *temp = data->stack_a.top;
        data->stack_a.top = data->stack_a.top->next;
        free(temp);
    }

    while (data->stack_b.top != NULL) {
        t_node *temp = data->stack_b.top;
        data->stack_b.top = data->stack_b.top->next;
        free(temp);
    }

    // Free the main structure
    free(data);
}
