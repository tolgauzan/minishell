/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:15:00 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/07 07:15:00 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPES_H
# define MINISHELL_TYPES_H

# include <sys/types.h>

typedef enum e_error
{
	E_SUCCESS,
	E_EMPTY,
	E_QUOTE_SQUOTE,
	E_QUOTE_DQUOTE,
	E_SYNTAX_PIPE,
	E_SYNTAX_REDIR_IN,
	E_SYNTAX_REDIR_OUT,
	E_SYNTAX_REDIR_APPEND,
	E_SYNTAX_HEREDOC,
	E_SYNTAX_NEWLINE,
	E_HEREDOC_FAIL,
	E_HEREDOC_EINTR
}	t_error;

typedef enum e_token_type
{
	T_UQUOTE_WORD,
	T_SQUOTE_WORD,
	T_DQUOTE_WORD,
	T_SEPARATOR,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_HEREDOC
}	t_token_type;

typedef enum e_redir_type
{
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef struct s_env_entry
{
	char	*key;
	char	*value;
}	t_env_entry;

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*left;
	struct s_gc	*right;
	int			height;
}	t_gc;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	int				was_expanded;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_redir
{
	t_redir_type	type;
	char			*filename;
	int				is_quoted;
	int				heredoc_read_fd;
	int				was_expanded;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	int				arg_count;
	t_redir			*redirs;
	int				redir_count;
	int				input;
	int				output;
	pid_t			pid;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

#endif
