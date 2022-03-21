/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:38:36 by crivers           #+#    #+#             */
/*   Updated: 2022/03/19 20:20:48 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	fill_and_sort(t_list *list, int *array, int size)
{
	int	i;

	i = 0;
	while (list)
	{
		array[i++] = list->elem;
		list = list->next;
	}
	ft_sort_int_tab(array, size);
}

void	init_params(t_push *checker, int size)
{
	int		*array;
	int		i;
	t_list	*tmp;

	tmp = checker->a;
	array = malloc(sizeof(int) * size);
	if (!array)
		exit(1);
	fill_and_sort(checker->a, array, size);
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->elem == array[i])
				tmp->pos = i;
			i++;
		}
		tmp = tmp->next;
	}
	free(array);
}
