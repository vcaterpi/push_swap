/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 00:13:58 by antondob          #+#    #+#             */
/*   Updated: 2020/04/09 15:40:59 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmds(t_push_swap *params)
{
	t_stack *tmp;

	if (ERROR != 0)
	{
		ft_putstr("Error\n");
		return ;
	}
	tmp = CMD_HEAD;
	while (tmp)
	{
		ft_printf("%s\n", cmd_name(TMP_NUM));
		tmp = tmp->next;
	}
}

void	print_checker(t_push_swap *params)
{
	if (ERROR != 0)
		ft_putstr("Error\n");
	else if (A_SORTED == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
