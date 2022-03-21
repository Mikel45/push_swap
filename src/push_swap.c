/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:39:50 by crivers           #+#    #+#             */
/*   Updated: 2022/03/19 19:27:26 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_push	vars;

	if (argc > 2)
	{
		vars.i = 1;
		while (vars.i < argc)
		{
			if (isnumber(argv[vars.i]))
				ft_lstadd_back(&(vars.a), ft_lstnew(ft_atoi(argv[vars.i++])));
			else
				error_case();
		}
		if (check_same(vars.a))
			error_case();
		if (is_sorted(vars.a))
		{
			free_structs(&vars.a, &vars.b);
			return (0);
		}
		init_params(&vars, argc - 1);
		start_sort(&vars, argc);
		free_structs(&vars.a, &vars.b);
	}
	else if (argc == 2)
		check_one(argv[1]);
}
