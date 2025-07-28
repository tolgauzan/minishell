/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:07 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:50:07 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	bytes_written;
	size_t	strlen;

	if (s && fd >= 0)
	{
		strlen = ft_strlen(s);
		bytes_written = write(fd, s, strlen);
		while (bytes_written != -1 && (size_t)bytes_written < strlen)
		{
			strlen -= bytes_written;
			s += bytes_written;
			bytes_written = write(fd, s, strlen);
		}
	}
}
