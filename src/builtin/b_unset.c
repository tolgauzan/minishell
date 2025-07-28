/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:59 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:59 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_cmd *cmd)
{
	int	i;
	int	status;

	status = 0;
	i = 1;
	while (cmd->args[i])
	{
		if (!is_valid_id(cmd->args[i], '\0'))
		{
			print_err("unset: `");
			print_err(cmd->args[i]);
			print_err("': not a valid identifier\n");
			status = 1;
		}
		else
			unset_env(cmd->args[i]);
		i++;
	}
	if (status)
	{
		set_exit_status(1);
		return (1);
	}
	set_exit_status(0);
	return (0);
}
