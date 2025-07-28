/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:31:43 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/13 07:31:43 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	is_valid_id(char *format, char stop_char)
{
	int	i;

	if (!format || !format[0])
		return (0);
	if (!ft_isalpha((unsigned char)format[0]) && format[0] != '_')
		return (0);
	i = 1;
	while (format[i] && format[i] != stop_char)
	{
		if (!ft_isalnum((unsigned char)format[i]) && format[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	export_set(t_cmd *cmd)
{
	int	i;
	int	status;

	status = 0;
	i = 1;
	while (cmd->args[i])
	{
		if (!is_valid_id(cmd->args[i], '='))
		{
			print_err("export: `");
			print_err(cmd->args[i]);
			print_err("': not a valid identifier\n");
			status = 1;
		}
		else
			export_env(cmd->args[i]);
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

int	builtin_export(t_cmd *cmd, int fd[2])
{
	if (cmd->arg_count == 1)
		return (print_sorted_exports(*get_env(), fd));
	else
		return (export_set(cmd));
}
