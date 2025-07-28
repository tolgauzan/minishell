/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 09:59:16 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/12 09:59:16 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "string.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int	print_redir_error(char *filename, int ambiguous)
{
	print_err("-minishell: ");
	if (filename && *filename)
	{
		print_err(filename);
		print_err(": ");
	}
	if (ambiguous)
		print_err("ambiguous redirect\n");
	else
	{
		print_err(strerror(errno));
		print_err("\n");
	}
	set_exit_status(1);
	return (1);
}

int	apply_redir_fd(t_cmd *cmd, t_redir *redir, int flags)
{
	int	fd;

	if (redir->was_expanded && redir->filename && *redir->filename == '$')
		return (print_redir_error(redir->filename, 1));
	fd = open(redir->filename, flags, 0644);
	if (fd == -1)
		return (print_redir_error(redir->filename, 0));
	if ((flags & O_WRONLY) == 0)
	{
		if (cmd->input != STDIN_FILENO)
			close(cmd->input);
		cmd->input = fd;
	}
	else
	{
		if (cmd->output != STDOUT_FILENO)
			close(cmd->output);
		cmd->output = fd;
	}
	return (0);
}

int	handle_single_redir(t_cmd *cmd, t_redir *redir)
{
	if (redir->type == REDIR_HEREDOC)
	{
		if (redir->heredoc_read_fd != -1)
		{
			if (cmd->input != STDIN_FILENO)
				close(cmd->input);
			cmd->input = redir->heredoc_read_fd;
		}
		return (0);
	}
	if (redir->type == REDIR_INPUT)
		return (apply_redir_fd(cmd, redir, O_RDONLY));
	if (redir->type == REDIR_OUTPUT)
		return (apply_redir_fd(cmd, redir, O_WRONLY | O_CREAT | O_TRUNC));
	if (redir->type == REDIR_APPEND)
		return (apply_redir_fd(cmd, redir, O_WRONLY | O_CREAT | O_APPEND));
	return (0);
}

int	process_cmd_redirections(t_cmd *cmd)
{
	int	i;

	if (!cmd->redirs)
		return (0);
	i = 0;
	while (i < cmd->redir_count)
	{
		if (handle_single_redir(cmd, &cmd->redirs[i]))
			return (1);
		i++;
	}
	return (0);
}
