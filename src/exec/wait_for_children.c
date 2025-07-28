/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_children.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:00:10 by aserbest          #+#    #+#             */
/*   Updated: 2025/07/27 18:57:48 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"

int	handle_signal_status(int status)
{
	int	sig;

	sig = WTERMSIG(status);
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (128 + sig);
	}
	else if (sig == SIGQUIT)
	{
		print_err("Quit");
		if (WCOREDUMP(status))
			print_err(" (core dumped)");
		print_err("\n");
		return (128 + sig);
	}
	else
		return (128 + sig);
}

int	wait_for_child(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (handle_signal_status(status));
	return (1);
}

int	wait_for_children(t_cmd *cmd_list)
{
	t_cmd	*cur;
	int		exit_status;

	cur = cmd_list;
	while (cur)
	{
		if (cur->pid > 0)
			exit_status = wait_for_child(cur->pid);
		cur = cur->next;
	}
	return (exit_status);
}
