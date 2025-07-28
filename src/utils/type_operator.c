/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:54 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:54 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_types.h"

int	is_operator(t_token_type type)
{
	return (type == T_PIPE
		|| type == T_REDIR_IN
		|| type == T_REDIR_OUT
		|| type == T_REDIR_APPEND
		|| type == T_HEREDOC);
}

int	is_redir(t_token_type type)
{
	return (type == T_REDIR_IN
		|| type == T_REDIR_OUT
		|| type == T_REDIR_APPEND
		|| type == T_HEREDOC);
}

int	is_pipe(t_token_type type)
{
	return (type == T_PIPE);
}

int	is_separator(t_token_type type)
{
	return (type == T_SEPARATOR);
}
