/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:42 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:42 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	builtin_env(t_list *env_list, int fd[2])
{
	t_env_entry	*entry;

	while (env_list)
	{
		entry = (t_env_entry *)env_list->content;
		if (entry && entry->value)
		{
			ft_putstr_fd(entry->key, fd[1]);
			ft_putstr_fd("=", fd[1]);
			ft_putstr_fd(entry->value, fd[1]);
			ft_putstr_fd("\n", fd[1]);
		}
		env_list = env_list->next;
	}
	set_exit_status(0);
}
