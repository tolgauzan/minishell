/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:17:38 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/23 21:17:38 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

static void	close_heredoc_fds(t_cmd *cmd_list)
{
	t_cmd	*curr;
	int		i;

	curr = cmd_list;
	while (curr)
	{
		if (curr->redirs)
		{
			i = 0;
			while (i < curr->redir_count)
			{
				if (curr->redirs[i].type == REDIR_HEREDOC
					&& curr->redirs[i].heredoc_read_fd != -1)
				{
					close(curr->redirs[i].heredoc_read_fd);
					curr->redirs[i].heredoc_read_fd = -1;
				}
				i++;
			}
		}
		curr = curr->next;
	}
}

static t_error	wait_heredoc(pid_t pid, int *pipe_fd)
{
	int		status;
	t_error	err;

	setup_signals_parent_ignore();
	close(pipe_fd[1]);
	if (waitpid(pid, &status, 0) == -1)
	{
		close(pipe_fd[0]);
		setup_signals_prompt();
		return (E_HEREDOC_FAIL);
	}
	err = E_SUCCESS;
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 130)
			return (E_HEREDOC_EINTR);
		else if (WEXITSTATUS(status) == 1)
			return (E_HEREDOC_FAIL);
	}
	if (err != E_SUCCESS)
		close(pipe_fd[0]);
	setup_signals_prompt();
	return (err);
}

static t_error	heredoc_fork(t_redir *redir)
{
	int		pipe_fd[2];
	pid_t	pid;
	t_error	err;

	if (pipe(pipe_fd) == -1)
		return (E_HEREDOC_FAIL);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (E_HEREDOC_FAIL);
	}
	if (pid == 0)
	{
		setup_signals_heredoc();
		close(pipe_fd[0]);
		err = read_heredoc(redir, pipe_fd[1]);
		close(pipe_fd[1]);
		exit(err == E_HEREDOC_FAIL);
	}
	err = wait_heredoc(pid, pipe_fd);
	if (err == E_SUCCESS)
		redir->heredoc_read_fd = pipe_fd[0];
	return (err);
}

static t_error	process_cmd_heredocs(t_cmd *curr, t_cmd *cmd_list)
{
	int		i;
	t_error	err;

	if (!curr->redirs)
		return (E_SUCCESS);
	i = 0;
	while (i < curr->redir_count)
	{
		if (curr->redirs[i].type == REDIR_HEREDOC)
		{
			err = heredoc_fork(&curr->redirs[i]);
			if (err != E_SUCCESS)
			{
				close_heredoc_fds(cmd_list);
				return (err);
			}
		}
		i++;
	}
	return (E_SUCCESS);
}

t_error	process_heredocs(t_cmd *cmd_list)
{
	t_error	err;
	t_cmd	*curr;

	curr = cmd_list;
	while (curr)
	{
		err = process_cmd_heredocs(curr, cmd_list);
		if (err != E_SUCCESS)
			return (err);
		curr = curr->next;
	}
	return (E_SUCCESS);
}
