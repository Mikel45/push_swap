/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:42:24 by crivers           #+#    #+#             */
/*   Updated: 2022/03/20 17:56:20 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	isnumber(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}

void	init_stack(int argc, char **argv, t_push *vars)
{
	vars->i = 1;
	while (vars->i < argc)
	{
		if (isnumber(argv[vars->i]))
			ft_lstadd_back(&(vars->a), ft_lstnew(ft_atoi(argv[vars->i++])));
		else
			error_bonus();
	}
	if (check_same(vars->a))
		error_bonus();
}

int	is_sorted(t_list *list)
{
	int	prevelem;

	prevelem = list->elem;
	while (list->next)
	{
		list = list->next;
		if (prevelem >= list->elem)
			return (0);
		prevelem = list->elem;
	}
	return (1);
}

int	check_same(t_list *list)
{
	t_list	*cpy;

	while (list->next)
	{
		cpy = list->next;
		while (cpy)
		{
			if (cpy->elem == list->elem)
				return (1);
			cpy = cpy->next;
		}
		list = list->next;
	}
	return (0);
}
