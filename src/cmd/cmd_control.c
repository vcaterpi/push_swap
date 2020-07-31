/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:19:34 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:34:11 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_control(t_push_swap *params)
{
	if (!B_1)
		return ;
	ROT = (B_NUM_1 > B_NUM_0 ? B_SIZE - 1 :
		ROT % B_SIZE + B_SIZE * (ROT < 0));
}

char	*cmd_name(int nbr)
{
	char *instructions[12];

	instructions[0] = "sa";
	instructions[1] = "sb";
	instructions[2] = "ss";
	instructions[3] = "pa";
	instructions[4] = "pb";
	instructions[5] = "ra";
	instructions[6] = "rb";
	instructions[7] = "rr";
	instructions[8] = "rra";
	instructions[9] = "rrb";
	instructions[10] = "rrr";
	instructions[11] = NULL;
	return (instructions[nbr]);
}

int		cmd_num(char *line)
{
	int		i;
	char	*instructions[12];

	i = -1;
	instructions[0] = "sa";
	instructions[1] = "sb";
	instructions[2] = "ss";
	instructions[3] = "pa";
	instructions[4] = "pb";
	instructions[5] = "ra";
	instructions[6] = "rb";
	instructions[7] = "rr";
	instructions[8] = "rra";
	instructions[9] = "rrb";
	instructions[10] = "rrr";
	instructions[11] = NULL;
	while (instructions[++i])
		if (ft_strequ(instructions[i], line))
			return (i);
	return (-1);
}

void	cmd_exec(t_push_swap *params)
{
	void	(*operations[12])(t_push_swap*);

	operations[0] = sa;
	operations[1] = sb;
	operations[2] = ss;
	operations[3] = pa;
	operations[4] = pb;
	operations[5] = ra;
	operations[6] = rb;
	operations[7] = rr;
	operations[8] = rra;
	operations[9] = rrb;
	operations[10] = rrr;
	operations[11] = NULL;
	operations[CMD_NUM](params);
}

void	cmds_apply(t_push_swap *params)
{
	if (ERROR)
		return ;
	while (CMD_HEAD)
	{
		cmd_exec(params);
		ft_stkpop(&CMD_HEAD, sizeof(int));
	}
}
