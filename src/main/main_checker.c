/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:05:30 by antondob          #+#    #+#             */
/*   Updated: 2020/04/08 02:35:00 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_push_swap params;

	MODE = 1;
	params_init(&params);
	read_check_stack(&params, argc, argv);
	read_check_cmds(&params);
	cmds_apply(&params);
	check_sorted(&params);
	print_checker(&params);
	params_free(&params);
}
