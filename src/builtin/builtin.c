/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:52:02 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:52:02 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_cmd *cmd, int fd[2], int print)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (!ft_strcmp(cmd->args[0], "env"))
		builtin_env(*get_env(), fd);
	else if (!ft_strcmp(cmd->args[0], "echo"))
		builtin_echo(cmd, fd);
	else if (!ft_strcmp(cmd->args[0], "pwd"))
		builtin_pwd(cmd, fd);
	else if (!ft_strcmp(cmd->args[0], "export"))
		builtin_export(cmd, fd);
	else if (!ft_strcmp(cmd->args[0], "cd"))
		builtin_cd(cmd);
	else if (!ft_strcmp(cmd->args[0], "unset"))
		builtin_unset(cmd);
	else if (!ft_strcmp(cmd->args[0], "exit"))
		builtin_exit(cmd, print);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	return (0);
}
