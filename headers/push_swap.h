/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:29:29 by crivers           #+#    #+#             */
/*   Updated: 2022/03/19 19:25:28 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		ft_atoi(const char *str);
int		isnumber(char *str);
int		is_sorted(t_list *list);
int		check_same(t_list *list);
void	error_case(void);
void	check_one(char *str);
void	free_structs(t_list **a, t_list**b);

void	fill_and_sort(t_list *list, int *array, int size);
void	ft_sort_int_tab(int *tab, int size);
void	init_params(t_push *checkers, int size);

t_list	*ft_lstnew(int element);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

void	swap_elements(t_list **lst, char *stack);
void	rotate(t_list **lst, char *stack);
void	reverse_rotate(t_list **lst, char *stack);
void	push_command(t_list **list_one, t_list **list_two, char *stack);

void	find_max_min(t_list *list, t_push *checkers);

void	start_sort(t_push *checker, int argc);
void	three_sort(t_push *checker);
void	four_sort(t_push *checker);
void	five_sort(t_push *checker);
void	bigsort(t_list **a, t_list **b, int argc, int check);

#endif