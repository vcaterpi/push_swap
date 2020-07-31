/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 00:30:28 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:33:24 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_push_swap params;

	MODE = 0;
	params_init(&params);
	read_check_stack(&params, argc, argv);
	quicksort(&params);
	optimize_result(&params);
	print_cmds(&params);
	params_free(&params);
}
