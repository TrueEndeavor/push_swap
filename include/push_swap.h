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

/* perror(), pid_t */
# include <stdio.h>

/* Libft functions */
# include "libft.h"

/* *****************************   STRUCTURES   *******************************/
typedef struct ListNode {
    int data;
    int lis;
    struct ListNode* next;
    struct ListNode* prev;
} t_list_node;

typedef struct StackList{
    t_list_node* top;
    t_list_node* bottom;
    int size;
} t_stack_list;

typedef struct {
    t_stack_list stackA;
    t_stack_list stackB;
    t_list_node* head; // Head of the linked list for LIS calculation
    int lisLength; // Length of the Longest Increasing Subsequence
} t_push_swap_data;

/* *****************************   CONSTANTS   ********************************/

/* This program needs atleast 5 parameters minimum on the command line. 
*/
# define MIN_COMMAND_LINE_ARGS 5

# define READ 0
# define WRITE 1
# define COMMAND_NOT_FOUND 127

/* This is the file permission mode for the created file. In this case, 
 * it represents the octal value 0644, which sets the permissions of 
 * the file to rw-r--r--. This means the owner has read and write 
 * permissions, while others have read-only permissions.
 */
# ifndef OUTFILE_PERM
#  define OUTFILE_PERM 0000644
# endif

/* **************************   ERROR MESSAGES   ******************************/

# define ERR_BAD_ARGUMENTS_COUNT "Bad number of arguments"
# define ERR_FILE_DOESNT_EXIST "No such file or directory"
# define ERR_DIR_DOESNT_EXIST "not a directory"
# define ERR_PERMISSION_DENIED "Permission denied"
# define ERR_COMMAND_NOT_FOUND "command not found"
# define PIPEX_USAGE "./pipex infile \"cmd1 opts\" \"cmd2 opts\" outfile (or) ./pipex here_doc LIMITER cmd cmd1 file"

/* ****************************   FUNCTIONS   *********************************/
int					isValidInput(int ac, char **av);

t_push_swap_data	*initialize_push_swap_data(int ac, char **av);
t_list_node 		*create_new_node(int data);
void				free_push_swap_data(t_push_swap_data *data);
void				print_push_swap_data(t_push_swap_data* data);

#endif
