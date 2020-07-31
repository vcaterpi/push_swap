/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:59:12 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/07/31 17:36:07 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *params)
{
	int nbr;

	if (!A_0 || !A_1)
		return ;
	nbr = A_NUM_0;
	A_NUM_0 = A_NUM_1;
	A_NUM_1 = nbr;
	nbr = cmd_num("sa");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}

void	sb(t_push_swap *params)
{
	int	nbr;

	if (!B_0 || !B_1)
		return ;
	nbr = B_NUM_0;
	B_NUM_0 = B_NUM_1;
	B_NUM_1 = nbr;
	nbr = cmd_num("sb");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}

void	ss(t_push_swap *params)
{
	sa(params);
	sb(params);
}
