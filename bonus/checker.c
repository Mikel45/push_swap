/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:26:00 by crivers           #+#    #+#             */
/*   Updated: 2022/03/21 16:44:40 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	parse_command(char **cmd)
{
	int	rd;
	int	i;

	i = 0;
	rd = 0;
	rd = read(0, &(*cmd)[i], 1);
	while (rd > 0 && (*cmd)[i] != '\n')
	{
		i++;
		rd = read(0, &(*cmd)[i], 1);
		if (i > 4)
			return (0);
	}
	(*cmd)[i] = '\0';
	return (1);
}

void	print_res(int check, char *cmd, t_list **a, t_list **b)
{
	if (check == 1)
		write(1, "OK\n", 3);
	if (check == 2)
		write(2, "KO\n", 3);
	free(cmd);
	ft_lstclear(a);
	ft_lstclear(b);
	exit(0);
}

void	error_bonus(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

void	check_cmd(t_list **a, t_list **b, char *cmd)
{
	if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "sa") == 0)
		swap(a, b, 1);
	else if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "sb") == 0)
		swap(a, b, 2);
	else if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "ss") == 0)
		swap(a, b, 3);
	else if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "ra") == 0)
		rotate(a, b, 1);
	else if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "rb") == 0)
		rotate(a, b, 2);
	else if (ft_strlen(cmd) == 3 && ft_strcmp(cmd, "rrr") == 0)
		rotate(a, b, 3);
	else if (ft_strlen(cmd) == 3 && ft_strcmp(cmd, "rra") == 0)
		reverse_rotate(a, b, 1);
	else if (ft_strlen(cmd) == 3 && ft_strcmp(cmd, "rrb") == 0)
		reverse_rotate(a, b, 2);
	else if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "rr") == 0)
		reverse_rotate(a, b, 3);
	else if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "pa") == 0)
		push_command(b, a);
	else if (ft_strlen(cmd) == 2 && ft_strcmp(cmd, "pb") == 0)
		push_command(a, b);
	else
		error_bonus();
}

int	main(int argc, char **argv)
{
	t_push	vars;
	char	*cmd;

	cmd = malloc(4);
	if (!cmd || argc == 1)
		exit(1);
	init_stack(argc, argv, &vars);
	while (1)
	{
		if (!parse_command(&cmd))
			error_bonus();
		if (ft_strlen(cmd) == 0)
			break ;
		check_cmd(&vars.a, &vars.b, cmd);
	}
	if (is_sorted(vars.a) && ft_lstsize(vars.b) == 0)
		print_res(1, cmd, &vars.a, &vars.b);
	print_res(2, cmd, &vars.a, &vars.b);
}
