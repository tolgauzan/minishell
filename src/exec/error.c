/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:56:16 by aserbest          #+#    #+#             */
/*   Updated: 2025/07/27 18:46:22 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	command_not_found(t_cmd *cmd)
{
	print_err("minishell: ");
	print_err(cmd->args[0]);
	print_err(": command not found\n");
	exit(127);
}

void	execve_error(t_cmd *cmd)
{
	print_err("minishell: ");
	print_err(cmd->args[0]);
	print_err(": ");
	print_err(strerror(errno));
	print_err("\n");
	exit(126);
}

void	permission_denied(t_cmd *cmd)
{
	print_err("minishell: ");
	print_err(cmd->args[0]);
	print_err(": Permission denied\n");
	exit(126);
}

void	no_such_file_or_dir(t_cmd *cmd)
{
	print_err("minishell: ");
	print_err(cmd->args[0]);
	print_err(": No such file or directory\n");
	exit(127);
}

void	is_a_directory(t_cmd *cmd)
{
	print_err("minishell: ");
	print_err(cmd->args[0]);
	print_err(": Is a directory\n");
	exit(126);
}
