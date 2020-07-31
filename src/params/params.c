/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:08:32 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:32:43 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	params_free(t_push_swap *params)
{
	ft_stkdel(&A_HEAD, sizeof(int));
	ft_stkdel(&B_HEAD, sizeof(int));
	ft_stkdel(&CMD_HEAD, sizeof(int));
}

void	params_init(t_push_swap *params)
{
	A_HEAD = NULL;
	B_HEAD = NULL;
	CMD_HEAD = NULL;
	A_SIZE = 0;
	B_SIZE = 0;
	A_SORTED = 1;
	ERROR = 0;
	ROT = 0;
}
