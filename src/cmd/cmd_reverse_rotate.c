/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:16:36 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/04/07 01:12:46 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *params)
{
	int	*data;
	int	nbr;

	data = ft_stkpop_back(&A_HEAD, sizeof(int));
	if (!data)
	{
		ERROR = 6;
		return ;
	}
	ft_stkpush(&A_HEAD, data, sizeof(int));
	free(data);
	nbr = cmd_num("rra");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}

void	rrb(t_push_swap *params)
{
	int	*data;
	int	nbr;

	data = ft_stkpop_back(&B_HEAD, sizeof(int));
	if (!data)
	{
		ERROR = 6;
		return ;
	}
	ft_stkpush(&B_HEAD, data, sizeof(int));
	free(data);
	--ROT;
	rot_control(params);
	nbr = cmd_num("rrb");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}

void	rrr(t_push_swap *params)
{
	rra(params);
	rrb(params);
}
