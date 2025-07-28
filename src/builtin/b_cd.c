/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:34 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:34 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "minishell.h"
#include "unistd.h"
#include <string.h>
#include <limits.h>

static int	handle_getcwd_err(char *context)
{
	print_err("-minishell: cd: ");
	print_err(context);
	print_err(" error\n");
	set_exit_status(1);
	return (1);
}

static int	handle_chdir_err(char *target_dir)
{
	print_err("-minishell: cd: ");
	print_err(target_dir);
	print_err(": ");
	print_err(strerror(errno));
	print_err("\n");
	set_exit_status(1);
	return (1);
}

static int	change_dir(char *target_dir, char *old_pwd, char *new_pwd)
{
	char	*oldpwd_str;
	char	*pwd_str;

	if (chdir(target_dir) != 0)
		return (handle_chdir_err(target_dir));
	if (!getcwd(new_pwd, PATH_MAX))
		return (handle_getcwd_err("getcwd"));
	oldpwd_str = gc_safe(ft_strjoin("OLDPWD=", old_pwd));
	pwd_str = gc_safe(ft_strjoin("PWD=", new_pwd));
	export_env(oldpwd_str);
	export_env(pwd_str);
	gc_free(oldpwd_str);
	gc_free(pwd_str);
	set_exit_status(0);
	return (0);
}

static char	*get_target_directory(t_cmd *cmd)
{
	char	*home;

	if (cmd->arg_count == 1)
	{
		home = get_env_value("HOME");
		if (!home)
		{
			print_err("-minishell: cd: HOME not set\n");
			set_exit_status(1);
			return (NULL);
		}
		return (home);
	}
	return (cmd->args[1]);
}

int	builtin_cd(t_cmd *cmd)
{
	char	*target_dir;
	char	old_pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];

	if (cmd->arg_count > 2)
	{
		print_err("-minishell: cd: too many arguments\n");
		set_exit_status(1);
		return (1);
	}
	target_dir = get_target_directory(cmd);
	if (!target_dir)
		return (1);
	if (!getcwd(old_pwd, sizeof(old_pwd)))
		return (handle_getcwd_err("getcwd"));
	return (change_dir(target_dir, old_pwd, new_pwd));
}
