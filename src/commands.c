/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:08:32 by crivers           #+#    #+#             */
/*   Updated: 2022/03/17 19:48:47 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_elements(t_list **lst, char *stack)
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	tmp = list->next;
	if (tmp->next)
		(tmp->next)->prev = list;
	list->prev = tmp;
	list->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = list;
	*lst = tmp;
	write(1, "s", 1);
	write(1, stack, 2);
}

void	rotate(t_list **lst, char *stack)
{
	t_list	*tmp;
	t_list	*list;

	tmp = *lst;
	list = *lst;
	while (list->next)
		list = list->next;
	list->next = tmp;
	*lst = tmp->next;
	(tmp->next)->prev = NULL;
	tmp->prev = list;
	tmp->next = NULL;
	write(1, "r", 1);
	write(1, stack, 2);
}

void	reverse_rotate(t_list **lst, char *stack)
{
	t_list	*tmp;
	t_list	*list;

	tmp = *lst;
	list = *lst;
	while (list->next)
		list = list->next;
	(list->prev)->next = NULL;
	list->next = tmp;
	list->prev = NULL;
	tmp->prev = list;
	*lst = list;
	write(1, "rr", 2);
	write(1, stack, 2);
}

void	push_command(t_list **list_one, t_list **list_two, char *stack)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*list_one)->next)
	{
		tmp = (*list_one)->next;
		(*list_one)->prev = NULL;
	}
	ft_lstadd_front(list_two, *list_one);
	*list_one = tmp;
	write(1, "p", 1);
	write(1, stack, 2);
}
