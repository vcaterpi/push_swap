/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:06:53 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:35:17 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subst_cmds(t_stack **head, t_stack *curr, int count, int cmd)
{
	int		count_1;
	int		count_2;
	int		nbr;

	count_1 = count;
	count_2 = count;
	while (CURR_NUM == cmd || CURR_NUM == (cmd + 1))
	{
		if ((CURR_NUM == cmd && --count_1 >= 0)
			|| (CURR_NUM == (cmd + 1) && --count_2 >= 0))
		{
			ft_stkdel_node(head, &curr);
			continue ;
		}
		curr = curr->next;
	}
	nbr = cmd + 2;
	while (count--)
		ft_stkpush_middle(head, curr, &nbr, sizeof(int));
}

void		optimize_cmnds(t_stack **head, t_stack *curr, int cmd)
{
	int		count_1;
	int		count_2;
	t_stack	*tmp;

	count_1 = 0;
	count_2 = 0;
	if (!curr || !(curr = curr->next))
		return ;
	tmp = curr;
	while ((CURR_NUM == cmd && ++count_1) ||
		(CURR_NUM == (cmd + 1) && ++count_2))
		curr = curr->next;
	if (ft_min_2(count_1, count_2))
		subst_cmds(head, tmp, ft_min_2(count_1, count_2), cmd);
	optimize_cmnds(head, curr, cmd);
}

void		optimize_result(t_push_swap *params)
{
	optimize_cmnds(&CMD_HEAD, CMD_HEAD, cmd_num("ra"));
	optimize_cmnds(&CMD_HEAD, CMD_HEAD, cmd_num("rra"));
}
