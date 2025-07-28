/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:52:34 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:52:34 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*get_exit_status_ptr(void)
{
	static int	status = 0;

	return (&status);
}

void	set_exit_status(int status)
{
	int	*exit_status;

	exit_status = get_exit_status_ptr();
	*exit_status = status;
}

int	get_exit_status(void)
{
	return (*get_exit_status_ptr());
}
