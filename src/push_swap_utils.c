/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:34:14 by crivers           #+#    #+#             */
/*   Updated: 2022/03/21 22:39:14 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			minus;

	i = 0;
	res = 0;
	minus = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res * minus > 2147483647 || res * minus < -2147483648)
			error_case();
	}
	return (res * minus);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isnumber(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*(str++)))
		return (0);
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
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

void	find_max_min(t_list *list, t_push *checkers)
{
	int	i;

	i = 1;
	checkers->max = list->elem;
	checkers->min = list->elem;
	checkers->pos_max = 0;
	checkers->pos_min = 0;
	while (list->next)
	{
		list = list->next;
		if (list->elem > checkers->max)
		{
			checkers->max = list->elem;
			checkers->pos_max = i;
		}
		if (list->elem < checkers->min)
		{
			checkers->min = list->elem;
			checkers->pos_min = i;
		}
		i++;
	}
}
