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

void	initialize_ps_data(void)
{
	t_ps_data	*data;
dprintf(1, "%lu\n", sizeof(t_ps_data));
	data = (t_ps_data *)malloc(sizeof(t_ps_data));
	if (data == NULL)
	{
		//return (NULL);
	}
	*data->stack_a.top = NULL;
	*data->stack_a.bottom = NULL;
	*data->stack_a.size = 0;

	data->stack_b.top = NULL;
	data->stack_b.bottom = NULL;
	data->stack_b.size = 0;

	data->head = NULL;
	data->lis_length = 0;
}

t_ps_data	*load_ps_data(int ac, char **av)
{
    initialize_ps_data();
 	for (int i = ac - 1; i >= 1; i--) {
        t_node* new_node = create_new_node(atoi(av[i]));

        // Add the new node to stackA
        if (data->stack_a.top == NULL) {
            data->stack_a.top = new_node;
            data->stack_a.bottom = new_node;
        } else {
            new_node->next = data->stack_a.top;
            data->stack_a.top = new_node;
        }
        data->stack_a.size++;
    }
    return data;
}

t_node *create_new_node(int data) 
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    new_node->data = data;
    new_node->lis = 0; // Initialize lis to 0
    new_node->next = NULL;
    return new_node;
}
