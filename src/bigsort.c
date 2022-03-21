/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:07:43 by crivers           #+#    #+#             */
/*   Updated: 2022/03/17 19:48:32 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	search_max(t_list *b, int i)
{
	int	n;

	n = 0;
	while (b)
	{
		if (b->pos == i)
			break ;
		b = b->next;
		n++;
	}
	return (n);
}

void	sort_b(t_list **a, t_list **b, int argc)
{
	int	max;
	int	half;
	int	place;

	max = argc - 2;
	while (*b)
	{
		half = (max + 1) / 2;
		place = search_max(*b, max);
		if ((*b)->pos == max)
		{
			push_command(b, a, "a\n");
			max--;
		}
		else if (place <= half && (*b)->pos != max)
			rotate(b, "b\n");
		else if (place > half && (*b)->pos != max)
			reverse_rotate(b, "b\n");
	}
}

void	bigsort(t_list **a, t_list **b, int argc, int check)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->pos <= i && i > 1)
		{
			push_command(a, b, "b\n");
			rotate(b, "b\n");
			i++;
		}
		else if ((*a)->pos <= (i + check))
		{
			push_command(a, b, "b\n");
			i++;
		}
		else if ((*a)->pos >= i)
			rotate(a, "a\n");
	}
	sort_b(a, b, argc);
}
