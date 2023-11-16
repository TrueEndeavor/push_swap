/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:19:04 by lannur-s          #+#    #+#             */
/*   Updated: 2023/10/18 18:46:51 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* *****************************   INCLUDES   ******************************* */
/* malloc(), free(), exit() */
# include <stdlib.h>

/* read(), write() */
# include <unistd.h>

/* Libft functions */
# include "libft.h"


/* *****************************   CONSTANTS   ********************************/


/* ****************************   FUNCTIONS   *********************************/
int			is_not_number(char *input_value);
int			is_overflow(char *input_value);

void		create_and_add_to_list(t_list **stack_a, int size, char **argv, int i);

//void	initialize_ps_data(void);
//t_ps_data	*load_ps_data(int ac, char **av);
//t_node			*create_new_node(int data);
//void				free_ps_data(t_ps_data *data);
//void				print_ps_data(t_ps_data *data);

int					lis(int arr[], int n);

#endif
