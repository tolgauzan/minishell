/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:08 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:08 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	start_i;
	size_t	size;

	start_i = 0;
	size = 0;
	if (!s)
		return (NULL);
	while (start_i < start && s[start_i])
		start_i++;
	while (size < len && s[size + start_i])
		size++;
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr[size] = '\0';
	while (size--)
	{
		substr[size] = s[start_i + size];
	}
	return (substr);
}
