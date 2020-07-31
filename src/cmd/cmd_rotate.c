/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:56:13 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/04/08 02:43:46 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *params)
{
	int	*data;
	int	nbr;

	if (!A_0 || !A_1)
		return ;
	data = ft_stkpop(&A_HEAD, sizeof(int));
	if (!data)
	{
		ERROR = 6;
		return ;
	}
	ft_stkpush_back(&A_HEAD, data, sizeof(int));
	free(data);
	nbr = cmd_num("ra");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}

void	rb(t_push_swap *params)
{
	int	*data;
	int	nbr;

	if (!B_0 || !B_1)
		return ;
	data = ft_stkpop(&B_HEAD, sizeof(int));
	if (!data)
	{
		ERROR = 6;
		return ;
	}
	ft_stkpush_back(&B_HEAD, data, sizeof(int));
	free(data);
	++ROT;
	rot_control(params);
	nbr = cmd_num("rb");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}

void	rr(t_push_swap *params)
{
	ra(params);
	rb(params);
}
