/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:45 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:45 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>

static char	*skip_whitespace(char *str)
{
	while (*str && is_whitespaces(*str))
		str++;
	return (str);
}

static int	is_numeric_string(char *str)
{
	str = skip_whitespace(str);
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	str = skip_whitespace(str);
	return (*str == '\0');
}

void	builtin_exit(t_cmd *cmd, int print)
{
	int	code;

	if (print)
		ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (cmd->arg_count == 1)
		exit(shutdown(0));
	if (cmd->arg_count >= 2 && !is_numeric_string(cmd->args[1]))
	{
		print_err("-minishell: exit: ");
		print_err(cmd->args[1]);
		print_err(": numeric argument required\n");
		set_exit_status(2);
		exit(shutdown(0));
	}
	if (cmd->arg_count > 2)
	{
		print_err("-minishell: exit: too many arguments\n");
		set_exit_status(1);
		return ;
	}
	code = ft_atoi(cmd->args[1]);
	set_exit_status((unsigned char)code);
	exit(shutdown(0));
}
