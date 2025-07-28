/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:55:05 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:55:05 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_args_in_cmd(t_token *start, t_token *end)
{
	t_token	*curr;
	int		count;

	count = 0;
	curr = start;
	while (curr && curr != end)
	{
		if (is_word(curr->type))
		{
			if (curr->prev && is_redir(curr->prev->type))
			{
				curr = curr->next;
				continue ;
			}
			count++;
		}
		curr = curr->next;
	}
	return (count);
}

static void	fill_arguments(t_cmd *cmd, t_token *start, t_token *end)
{
	t_token	*curr;
	int		arg_i;

	arg_i = 0;
	curr = start;
	while (curr && curr != end && arg_i < cmd->arg_count)
	{
		if (is_word(curr->type))
		{
			if (curr->prev && is_redir(curr->prev->type))
			{
				curr = curr->next;
				continue ;
			}
			cmd->args[arg_i] = curr->value;
			arg_i++;
		}
		curr = curr->next;
	}
	cmd->args[cmd->arg_count] = NULL;
}

void	parse_args(t_cmd *cmd, t_token *start, t_token *end)
{
	cmd->arg_count = count_args_in_cmd(start, end);
	if (cmd->arg_count == 0)
	{
		cmd->args = NULL;
		return ;
	}
	cmd->args = gc_safe(
			ft_calloc((cmd->arg_count + 1), sizeof(char *)));
	fill_arguments(cmd, start, end);
}
