/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 14:48:17 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 18:48:02 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_push_swap *params)
{
	if (A_NUM_0 > A_NUM_1 &&
		A_NUM_0 < A_NUM_2)
		sa(params);
	else if (A_NUM_0 > A_NUM_1)
		ra(params);
	else
		rra(params);
}

static void	choose_pivot(t_push_swap *params, int division)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = A_HEAD;
	while (tmp)
	{
		i = 0;
		tmp2 = A_HEAD;
		while (tmp2)
		{
			if (TMP_NUM > TMP2_NUM)
				++i;
			if (i > A_SIZE / division)
				break ;
			tmp2 = tmp2->next;
		}
		if (i == A_SIZE / division)
			break ;
		tmp = tmp->next;
	}
	PIVOT = TMP_NUM;
}

static void	optimized_rotate(t_push_swap *params, char stack)
{
	int		size;
	int		count;
	void	(*cmnd)(t_push_swap*);
	t_stack	*tmp;

	count = 0;
	size = (stack == 'b' ? B_SIZE : A_SIZE);
	if (!(tmp = (stack == 'b' ? B_HEAD : A_HEAD)))
		return ;
	if (A_SORTED)
		tmp = NULL;
	while ((stack == 'b' ? COND_1 && COND_2 : COND_3))
		tmp = tmp->next;
	count = (((stack == 'b') && (!tmp || !tmp->next)) ?
		size - ROT : count);
	if (stack == 'b')
		cmnd = (count > size / 2 ? rrb : rb);
	else
		cmnd = (count > size / 2 ? rra : ra);
	if (count > size / 2)
		count = size - count;
	while (!ERROR && count--)
		cmnd(params);
}

static void	sort_more(t_push_swap *params)
{
	int	count;
	int	division;
	int	*b_last;

	division = (A_SIZE < 300 ? 4 : 9);
	choose_pivot(params, division);
	count = A_SIZE / division;
	while (!ERROR && A_HEAD && count--)
	{
		b_last = ft_stklast(B_HEAD, sizeof(int));
		optimized_rotate(params, 'a');
		if (B_HEAD && (A_NUM_0 < B_NUM_0 ||
			A_NUM_0 > B_NUM_LAST))
			optimized_rotate(params, 'b');
		pb(params);
		rot_control(params);
		free(b_last);
	}
}

void		quicksort(t_push_swap *params)
{
	if (!ERROR && check_sorted(params))
	{
		optimized_rotate(params, 'b');
		while (B_HEAD)
			pa(params);
	}
	if (ERROR || A_SORTED)
		return ;
	if (A_SIZE == 2)
		ra(params);
	else if (A_SIZE == 3)
		sort_3(params);
	else
		sort_more(params);
	quicksort(params);
}
