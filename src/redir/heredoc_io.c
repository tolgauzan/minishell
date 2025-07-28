/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:03:09 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/23 21:03:09 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> 
#include <readline/readline.h>

static void	print_heredoc_warn_eof(char *delimiter)
{
	print_err("-minishell: warning: here-document delimited by ");
	print_err("end-of-file (wanted `");
	print_err(delimiter);
	print_err("')\n");
}

static t_error	write_line(char *line, int write_fd, int is_quoted)
{
	char	*expanded_line;

	if (is_quoted)
	{
		ft_putendl_fd(line, write_fd);
		return (E_SUCCESS);
	}
	expanded_line = expand_str(line);
	if (!expanded_line)
		return (E_HEREDOC_FAIL);
	ft_putendl_fd(expanded_line, write_fd);
	free(expanded_line);
	return (E_SUCCESS);
}

t_error	read_heredoc(t_redir *redir, int write_fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			print_heredoc_warn_eof(redir->filename);
			break ;
		}
		if (ft_strcmp(line, redir->filename) == 0)
		{
			free(line);
			break ;
		}
		if (write_line(line, write_fd, redir->is_quoted))
		{
			free(line);
			return (E_HEREDOC_FAIL);
		}
		free(line);
	}
	return (E_SUCCESS);
}
