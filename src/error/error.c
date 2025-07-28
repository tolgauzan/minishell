/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:13:15 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/19 20:13:15 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_constants.h"
#include <unistd.h>

void	print_err(char *err)
{
	ft_putstr_fd(err, STDERR_FILENO);
}

void	free_lists(t_token **token_list, t_cmd **cmd_list)
{
	if (token_list && *token_list)
		free_tokens(token_list);
	if (cmd_list && *cmd_list)
		free_cmds(cmd_list);
}

static void	print_syntax_error(t_error err)
{
	if (err == E_QUOTE_SQUOTE)
		print_err(E_SQUOTE);
	else if (err == E_QUOTE_DQUOTE)
		print_err(E_DQUOTE);
	else if (err == E_SYNTAX_PIPE)
		print_err(E_PIPE);
	else if (err == E_SYNTAX_REDIR_IN)
		print_err(E_REDIR_IN);
	else if (err == E_SYNTAX_REDIR_OUT)
		print_err(E_REDIR_OUT);
	else if (err == E_SYNTAX_REDIR_APPEND)
		print_err(E_REDIR_APPEND);
	else if (err == E_SYNTAX_HEREDOC)
		print_err(E_HEREDOC);
	else if (err == E_SYNTAX_NEWLINE)
		print_err(E_NEWLINE);
}

static int	get_error_status(t_error err)
{
	if (err >= E_QUOTE_SQUOTE && err <= E_SYNTAX_NEWLINE)
		return (2);
	else if (err == E_HEREDOC_EINTR)
		return (130);
	else if (err == E_HEREDOC_FAIL)
		return (1);
	return (0);
}

int	handle_error(t_error err, t_token **token_list, t_cmd **cmd_list)
{
	if (err == E_SUCCESS)
		return (1);
	print_syntax_error(err);
	set_exit_status(get_error_status(err));
	free_lists(token_list, cmd_list);
	return (0);
}
