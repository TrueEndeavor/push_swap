/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                            :+:      :+:    :+:   */
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


/* *****************************   STRUCTURES   ********************************/
typedef struct s_element
{
	int					value;
	int					position;
}	t_element;

/* ****************************   FUNCTIONS   *********************************/
int		ft_atoi_push_swap(const char *str);
void	create_and_add_to_list(t_list **stack_a, int ac, char **av, int index);
void	check_duplicate(t_list *stack_a, int value_to_check);
void	check_sorted(t_list **stack_a);
void	display_error(char *error_str);

void	perform_push_swap(t_list **stack_a, t_list **stack_b, int size);
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);

void	swap(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

void	push(t_list **dest, t_list **src);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);

void	rotate(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);

void	reverse_rotate(t_list **stack);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);

void	free_stack(t_list **stack);

t_element		*ft_int_lstnew(int content);
//void	initialize_ps_data(void);
//t_ps_data	*load_ps_data(int ac, char **av);
//t_node			*create_new_node(int data);
//void				free_ps_data(t_ps_data *data);
//void				print_ps_data(t_ps_data *data);

int					lis(int arr[], int n);


//..................................

void	ft_lst_split(t_list **stack_a, t_list **stack_b, int size);
void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i);
void	ft_lstcheck(t_list *stack_a, int check);
void	ft_lst_order(t_list **stack_a);
void	ft_lst_inverted(t_list **stack_a);
void	ft_lst_delete(t_list **stack);

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	ft_sort_three(t_list **stack_a);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);

void	ft_check_argv(int argc, char **argv, t_list **stack_a);
void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max);
void	ft_move_to_a(t_list **stack_a, t_list **stack_b);
int		ft_best_nbr_b(t_list **stack_b, int size_b,
			t_list **stack_a, int size_a);
int		ft_best_nbr_a(t_list *stack_a, int size, int *arr, int max);
int		ft_best_comb(int *arr_a, int *arr_b, int size);
int		ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size);
int		ft_move_a(int a, int b, t_list **stack_a, t_list **stack_b);
void	ft_search_min(t_list **stack_a, int size);

int		*ft_copy_cont(t_list *stack_a, int size);
int		*ft_intcpy(int	*arr, int size);

int		ft_the_needed(int min, int max, int size);
int		ft_the_needed_a(t_list *stack_a, int cont, int size);
int		ft_the_needed_b(int max, int size);
int		ft_max_nbr(int a, int b);
int		ft_min_nbr(int a, int b);
int		ft_max_or_min(t_list *stack_a, int cont, int size);
int		return_max_or_min(int cont, int *max_n_min, int size);

int		*ft_define_lis(int *dst, int size, int *max);
int		*ft_long_lis(int *dst, int *arr, int size, int *ret);
int		*ft_lis_util(int *dst, int *arr, int max, int size);
int		*ft_lis_util_helper(int max);

void	ft_exec_sort(t_list **stack_a, t_list **stack_b, char *str);
void	ft_rr_or_death(t_list **stack_a, t_list **stack_b, char *str);
void	ft_check_write_lst(t_list **stack_a, int argc, char **argv, int i);
void	ft_check_lst_inverted(t_list **stack_a);
void	ft_check_sort(t_list *stack_a);
void	ft_check_argv_c(int argc, char **argv, t_list **stack_a);
void	ft_sa_check(t_list **stack_a);
void	ft_sb_check(t_list **stack_b);
void	ft_ss_check(t_list **stack_a, t_list **stack_b);
void	ft_pa_check(t_list **stack_b, t_list **stack_a);
void	ft_pb_check(t_list **stack_a, t_list **stack_b);
void	ft_ra_check(t_list **stack_a);
void	ft_rb_check(t_list **stack_b);
void	reverse_rotate_both_check(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_botha_check(t_list **stack_a);
void	reverse_rotate_bothb_check(t_list **stack_b);
void	reverse_rotate_bothr_check(t_list **stack_a, t_list **stack_b);

#endif
