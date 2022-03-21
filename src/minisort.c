/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:19:29 by crivers           #+#    #+#             */
/*   Updated: 2022/03/17 19:49:16 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	three_sort(t_push *checker)
{
	if (is_sorted(checker->a))
		return ;
	if (is_sorted(checker->a->next))
	{
		if (checker->a->elem < checker->a->next->next->elem)
			swap_elements(&checker->a, "a\n");
		else
			rotate(&checker->a, "a\n");
	}
	else if (checker->a->elem > checker->a->next->elem
		&& checker->a->elem > checker->a->next->next->elem)
	{
		swap_elements(&checker->a, "a\n");
		reverse_rotate(&checker->a, "a\n");
	}
	else
	{
		reverse_rotate(&checker->a, "a\n");
		if (!is_sorted(checker->a))
			swap_elements(&checker->a, "a\n");
	}
}

void	four_sort(t_push *checker)
{
	find_max_min(checker->a, checker);
	if (checker->pos_min <= 2 && checker->pos_min != 0)
		while ((checker->pos_min)-- > 0)
			rotate(&checker->a, "a\n");
	else
		while ((checker->pos_min)-- - 2 > 0)
			reverse_rotate(&checker->a, "a\n");
	push_command(&checker->a, &checker->b, "b\n");
	three_sort(checker);
	push_command(&checker->b, &checker->a, "a\n");
}

void	five_sort(t_push *checker)
{
	find_max_min(checker->a, checker);
	if (checker->pos_min <= 3 && checker->pos_min != 0)
		while ((checker->pos_min)-- > 0)
			rotate(&checker->a, "a\n");
	else
		while ((checker->pos_min)-- - 3 > 0)
			reverse_rotate(&checker->a, "a\n");
	push_command(&checker->a, &checker->b, "b\n");
	find_max_min(checker->a, checker);
	if (checker->pos_min <= 2 && checker->pos_min != 0)
		while ((checker->pos_min)-- > 0)
			rotate(&checker->a, "a\n");
	else
		while ((checker->pos_min)-- - 2 > 0)
			reverse_rotate(&checker->a, "a\n");
	push_command(&checker->a, &checker->b, "b\n");
	three_sort(checker);
	push_command(&checker->b, &checker->a, "a\n");
	push_command(&checker->b, &checker->a, "a\n");
}
