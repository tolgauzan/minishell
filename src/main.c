/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:36:53 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/26 18:36:53 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_constants.h"
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

static char	**get_line(void)
{
	static char	*line = NULL;

	return (&line);
}

int	shutdown(int abort)
{
	rl_clear_history();
	cleanup_ignoreboth_history();
	gc_free_all();
	free(*get_line());
	if (abort)
	{
		print_err(E_MEM);
		exit(EXIT_FAILURE);
	}
	return (get_exit_status());
}

static void	process_line(char *line)
{
	t_token	*tokens;
	t_cmd	*cmds;

	if (!handle_error(lex(&tokens, line), &tokens, NULL))
		return ;
	expand(&tokens);
	parse(&cmds, tokens);
	if (!handle_error(process_heredocs(cmds), &tokens, &cmds))
		return ;
	execute(cmds);
	free_lists(&tokens, &cmds);
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	(void)argc;
	(void)argv;
	init_env(envp);
	setup_signals_prompt();
	while (1)
	{
		prompt = generate_prompt();
		*get_line() = readline(prompt);
		gc_free(prompt);
		if (*get_line() == NULL)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			break ;
		}
		if (should_add_to_history(*get_line()))
			add_history(*get_line());
		process_line(*get_line());
		free(*get_line());
		*get_line() = NULL;
	}
	return (shutdown(0));
}
