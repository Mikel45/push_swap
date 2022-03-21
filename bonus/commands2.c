/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:46:24 by crivers           #+#    #+#             */
/*   Updated: 2022/03/20 17:48:41 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	rotate(t_list **a, t_list **b, int choice)
{
	if (choice == 1)
		rotate_helper(a);
	else if (choice == 2)
		rotate_helper(b);
	else
	{
		rotate_helper(a);
		rotate_helper(b);
	}
}

void	reverse_rotate(t_list **a, t_list **b, int choice)
{
	if (choice == 1)
		reverse_rotate_helper(a);
	else if (choice == 2)
		reverse_rotate_helper(b);
	else
	{
		reverse_rotate_helper(a);
		reverse_rotate_helper(b);
	}
}
