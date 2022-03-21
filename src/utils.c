/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:39:27 by crivers           #+#    #+#             */
/*   Updated: 2022/03/20 17:38:57 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	error_case(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	start_sort(t_push *checker, int argc)
{
	if (argc == 3)
		swap_elements(&checker->a, "a\n");
	else if (argc == 4)
		three_sort(checker);
	else if (argc == 5)
		four_sort(checker);
	else if (argc == 6)
		five_sort(checker);
	else if (argc <= 101)
		bigsort(&checker->a, &checker->b, argc, 15);
	else
		bigsort(&checker->a, &checker->b, argc, 30);
}

void	check_one(char *str)
{
	if (!isnumber(str))
		error_case();
	ft_atoi(str);
}

void	free_structs(t_list **a, t_list**b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}
