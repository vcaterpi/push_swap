/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:22:52 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/07/31 17:25:56 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubling(t_push_swap *params, int nbr)
{
	t_stack	*tmp;

	tmp = A_HEAD;
	while (tmp && !ERROR)
	{
		if (TMP_NUM == nbr)
			ERROR = 5;
		tmp = tmp->next;
	}
}

void	read_check_cmds(t_push_swap *params)
{
	int		ret;
	char	*line;

	if (ERROR)
		return ;
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0 && !ERROR)
	{
		if (!(*line))
			break ;
		if ((ret = cmd_num(line)) == -1)
			ERROR = 3;
		ft_stkpush_back(&CMD_HEAD, &ret, sizeof(int));
		ft_strdel(&line);
	}
	if (!ERROR && (ret == -1))
		ERROR = 4;
	ft_strdel(&line);
}

void	fill_stack(t_push_swap *params, char **scan)
{
	int nbr;

	while (*scan && !ERROR)
	{
		if (!(ft_is_number(*scan)))
			ERROR = 2;
		nbr = ft_atoi(*scan);
		check_doubling(params, nbr);
		ft_stkpush_back(&A_HEAD, &nbr, sizeof(int));
		A_SIZE++;
		++scan;
	}
}

void	read_check_stack(t_push_swap *params, int argc, char **argv)
{
	char **scan;

	scan = NULL;
	if (argc < 2)
		ERROR = 1;
	if (argc == 2)
		scan = ft_strsplit(*(++argv), ' ');
	fill_stack(params, (argc == 2 ? scan : ++argv));
	if (scan)
		ft_double_free(scan, ft_double_len(scan));
}
