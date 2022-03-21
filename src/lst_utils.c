/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:21:36 by crivers           #+#    #+#             */
/*   Updated: 2022/03/19 20:21:38 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*ft_lstnew(int element)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		exit(1);
	list->elem = element;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
		new->prev = list;
	}
	else
		*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
		new->prev = NULL;
		*lst = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
	}
}
