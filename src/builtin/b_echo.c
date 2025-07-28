/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:38 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:38 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_n_option(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-')
		return (0);
	i = 1;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	builtin_echo(t_cmd *cmd, int fd[2])
{
	int	n_line;
	int	i;

	n_line = 1;
	i = 1;
	while (cmd->args[i] && is_valid_n_option(cmd->args[i]))
	{
		n_line = 0;
		i++;
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], fd[1]);
		if (cmd->args[i + 1])
			ft_putstr_fd(" ", fd[1]);
		i++;
	}
	if (n_line)
		ft_putstr_fd("\n", fd[1]);
	set_exit_status(0);
}
