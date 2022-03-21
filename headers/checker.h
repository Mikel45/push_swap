/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:46:42 by crivers           #+#    #+#             */
/*   Updated: 2022/03/20 17:52:49 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				elem;
	int				pos;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_push
{
	int				pos_max;
	int				pos_min;
	int				max;
	int				min;
	int				i;
	t_list			*a;
	t_list			*b;
}	t_push;

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	init_stack(int argc, char **argv, t_push *vars);
int		is_sorted(t_list *list);
int		isnumber(char *str);
int		check_same(t_list *list);

void	swap_helper(t_list **lst);
void	rotate_helper(t_list **lst);
void	reverse_rotate_helper(t_list **lst);
void	rotate(t_list **a, t_list **b, int choice);
void	swap(t_list **a, t_list **b, int choice);
void	reverse_rotate(t_list **a, t_list **b, int choice);
void	push_command(t_list **list_one, t_list **list_two);

t_list	*ft_lstnew(int element);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

void	error_bonus(void);

#endif