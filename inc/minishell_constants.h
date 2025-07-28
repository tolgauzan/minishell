/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_constants.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:15:00 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/07 07:15:00 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CONSTANTS_H
# define MINISHELL_CONSTANTS_H

# define P "$ "
# define H "@minishell:"
# define G "\001\033[1;32m\002"
# define B "\001\033[1;34m\002"
# define R "\001\033[0m\002"

# define E_MEM "-minishell: memory allocation error\n"
# define E_SQUOTE "-minishell: unexpected EOF while looking for matching `\''\n"
# define E_DQUOTE "-minishell: unexpected EOF while looking for matching `\"'\n"
# define E_PIPE "-minishell: syntax error near unexpected token `|'\n"
# define E_REDIR_IN "-minishell: syntax error near unexpected token `<'\n"
# define E_REDIR_OUT "-minishell: syntax error near unexpected token `>'\n"
# define E_REDIR_APPEND "-minishell: syntax error near unexpected token `>>'\n"
# define E_HEREDOC "-minishell: syntax error near unexpected token `<<'\n"
# define E_HEREDOC_EOF "-minishell: warning: here-document delimited by EOF\n"
# define E_NEWLINE "-minishell: syntax error near unexpected token `newline'\n"
# define E_SYNTAX "-minishell: syntax error near unexpected token\n"

#endif
