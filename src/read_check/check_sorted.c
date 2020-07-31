/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:29:36 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/07/31 17:31:21 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted(t_push_swap *params)
{
	t_stack *tmp;

	if (ERROR)
		return (0);
	A_SORTED = 1;
	tmp = A_HEAD;
	while (tmp->next && A_SORTED)
	{
		if (TMP_NUM_NEXT <= TMP_NUM)
			A_SORTED = 0;
		tmp = tmp->next;
	}
	return (A_SORTED);
}
