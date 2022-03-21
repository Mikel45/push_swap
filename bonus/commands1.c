/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:37:21 by crivers           #+#    #+#             */
/*   Updated: 2022/03/21 15:53:27 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	swap_helper(t_list **lst)
{
	t_list	*tmp;
	t_list	*list;

	if (!(*lst))
		return ;
	list = *lst;
	tmp = list->next;
	if (tmp->next)
		(tmp->next)->prev = list;
	list->prev = tmp;
	list->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = list;
	*lst = tmp;
}

void	rotate_helper(t_list **lst)
{
	t_list	*tmp;
	t_list	*list;

	if (!(*lst))
		return ;
	tmp = *lst;
	list = *lst;
	while (list->next)
		list = list->next;
	list->next = tmp;
	*lst = tmp->next;
	(tmp->next)->prev = NULL;
	tmp->prev = list;
	tmp->next = NULL;
}

void	reverse_rotate_helper(t_list **lst)
{
	t_list	*tmp;
	t_list	*list;

	if (!(*lst))
		return ;
	tmp = *lst;
	list = *lst;
	while (list->next)
		list = list->next;
	(list->prev)->next = NULL;
	list->next = tmp;
	list->prev = NULL;
	tmp->prev = list;
	*lst = list;
}

void	push_command(t_list **list_one, t_list **list_two)
{
	t_list	*tmp;

	if (!(*list_one))
		return ;
	tmp = NULL;
	if ((*list_one)->next)
	{
		tmp = (*list_one)->next;
		(*list_one)->prev = NULL;
	}
	ft_lstadd_front(list_two, *list_one);
	*list_one = tmp;
}

void	swap(t_list **a, t_list **b, int choice)
{
	if (choice == 1)
		swap_helper(a);
	else if (choice == 2)
		swap_helper(b);
	else
	{
		swap_helper(a);
		swap_helper(b);
	}
}
