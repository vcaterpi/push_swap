/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:43:18 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/04/07 01:13:05 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *params)
{
	int	*data;
	int	nbr;

	data = ft_stkpop(&B_HEAD, sizeof(int));
	if (!data)
	{
		ERROR = 6;
		return ;
	}
	ft_stkpush(&A_HEAD, data, sizeof(int));
	free(data);
	A_SIZE++;
	B_SIZE--;
	nbr = cmd_num("pa");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}

void	pb(t_push_swap *params)
{
	int	*data;
	int	nbr;

	data = ft_stkpop(&A_HEAD, sizeof(int));
	if (!data)
	{
		ERROR = 6;
		return ;
	}
	ft_stkpush(&B_HEAD, data, sizeof(int));
	free(data);
	B_SIZE++;
	A_SIZE--;
	nbr = cmd_num("pb");
	if (SORT_MODE)
		ft_stkpush_back(&CMD_HEAD, &nbr, sizeof(int));
}
