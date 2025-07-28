/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:56:16 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:56:16 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	setup_sigaction(int signum, void (*handler)(int), int flags)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = flags;
	sigaction(signum, &sa, NULL);
}

void	setup_signals_prompt(void)
{
	setup_sigaction(SIGINT, handle_sigint_prompt, SA_RESTART);
	setup_sigaction(SIGQUIT, SIG_IGN, 0);
}

void	setup_signals_heredoc(void)
{
	setup_sigaction(SIGINT, handle_sigint_heredoc, 0);
	setup_sigaction(SIGQUIT, SIG_IGN, 0);
}

void	setup_signals_parent_ignore(void)
{
	setup_sigaction(SIGINT, SIG_IGN, 0);
	setup_sigaction(SIGQUIT, SIG_IGN, 0);
}

void	setup_signals_execute_child(void)
{
	setup_sigaction(SIGINT, SIG_DFL, 0);
	setup_sigaction(SIGQUIT, SIG_DFL, 0);
}
