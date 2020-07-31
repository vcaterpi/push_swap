/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:27:39 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/07/31 18:47:58 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** shortcuts for stack A
*/

# define A_HEAD			params->a
# define A_0			params->a
# define A_NUM_0		*(int*)params->a->data
# define A_1			params->a->next
# define A_NUM_1		*(int*)params->a->next->data
# define A_2			params->a->next->next
# define A_NUM_2		*(int*)params->a->next->next->data
# define A_NUM_LAST		*a_last;
# define A_SIZE			params->a_size

/*
** shortcuts for stack B
*/

# define B_HEAD			params->b
# define B_0			params->b
# define B_NUM_0		*(int*)params->b->data
# define B_1			params->b->next
# define B_NUM_1		*(int*)params->b->next->data
# define B_2			params->b->next->next
# define B_NUM_2		*(int*)params->b->next->next->data
# define B_NUM_LAST		*b_last
# define B_SIZE			params->b_size

/*
** shortcuts for cmd list
*/

# define CMD_HEAD		params->cmd_list
# define CMD_NUM		*(int*)params->cmd_list->data
# define CMD_START		params.cmd_list

/*
** shortcuts for temporary stacks
*/

# define TMP_NUM		*(int*)tmp->data
# define TMP_NUM_NEXT	*(int*)tmp->next->data
# define TMP2_NUM		*(int*)tmp2->data
# define STK_NUM		*(int*)stack->data
# define STK_NUM_NEXT	*(int*)stack->next->data
# define CURR_NUM		*(int*)curr->data
# define CURR_NUM_NEXT	*(int*)curr->next->data

/*
** other shortcuts
** MODE (0 for sorter, 1 for checker)
*/

# define ROT			params->rotation
# define A_SORTED		params->is_sorted
# define ERROR			params->error
# define PIVOT			params->pivot
# define COND_1			(++count) && tmp && tmp->next
# define COND_2			(TMP_NUM < A_NUM_0 || TMP_NUM_NEXT > A_NUM_0)
# define COND_3			tmp && TMP_NUM >= PIVOT && ++count
# define MODE			params.mode
# define SORT_MODE		params->mode == 0

/*
** libft + printf
*/

# include "../libft/includes/ft_printf.h"

/*
** main push_swap structure
*/

typedef	struct		s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*cmd_list;
	int				error;
	int				is_sorted;
	int				a_size;
	int				b_size;
	int				rotation;
	int				pivot;
	int				mode;
}					t_push_swap;

/*
** read and check input
*/

void				read_check_cmds(t_push_swap *params);
void				read_check_stack(t_push_swap *params, int argc,\
						char **argv);
void				fill_stack(t_push_swap *params, char **scan);
int					check_sorted(t_push_swap *params);

/*
** process parameters
*/

void				params_init(t_push_swap *params);
void				params_free(t_push_swap *params);

/*
** proc and exec commands
*/

void				sa(t_push_swap *params);
void				sb(t_push_swap *params);
void				ss(t_push_swap *params);
void				pa(t_push_swap *params);
void				pb(t_push_swap *params);
void				ra(t_push_swap *params);
void				rb(t_push_swap *params);
void				rr(t_push_swap *params);
void				rra(t_push_swap *params);
void				rrb(t_push_swap *params);
void				rrr(t_push_swap *params);
void				cmds_apply(t_push_swap *params);
void				cmd_exec(t_push_swap *params);
int					cmd_num(char *line);
char				*cmd_name(int nbr);
void				optimize_result(t_push_swap *params);
void				rot_control(t_push_swap *params);

/*
** algorithm
*/

void				quicksort(t_push_swap *params);

/*
** output
*/

void				print_checker(t_push_swap *params);
void				print_cmds(t_push_swap *params);

/*
** ERROR types:
** 0 - default value of ERROR
** 1 - wrong number of arguments
** 2 - not valid argument
** 3 - invalid command
** 4 - gnl error
** 5 - doubling numbers
** 6 - memory allocation error
*/

#endif
