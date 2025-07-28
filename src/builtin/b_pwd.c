/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:56 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:56 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	builtin_pwd(t_cmd *cmd, int fd[2])
{
	char	cwd[PATH_MAX];

	(void)cmd;
	if (!getcwd(cwd, sizeof(cwd)))
	{
		print_err("pwd: error retrieving current directory: ");
		print_err("getcwd: ");
		print_err(strerror(errno));
		print_err("\n");
		set_exit_status(1);
		return (1);
	}
	else
	{
		ft_putstr_fd(cwd, fd[1]);
		ft_putstr_fd("\n", fd[1]);
		set_exit_status(0);
		return (0);
	}
}
