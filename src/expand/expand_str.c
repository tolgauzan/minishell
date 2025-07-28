/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:08 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:08 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static char	*append_variable_str(char *result, char *str, size_t *i)
{
	char	*var_value;
	char	*old_res;

	var_value = expand_var(str, i);
	if (!var_value)
		return (NULL);
	old_res = result;
	result = ft_strjoin(result, var_value);
	free(var_value);
	free(old_res);
	return (result);
}

static char	*append_literal_str(char *result, char *str,
		size_t start, size_t end)
{
	char	*temp;
	char	*old_res;

	if (end <= start)
		return (result);
	temp = ft_substr(str, start, end - start);
	if (!temp)
		return (NULL);
	old_res = result;
	result = ft_strjoin(result, temp);
	free(temp);
	free(old_res);
	return (result);
}

static char	*process_literal_str(char *result, char *str, size_t *i)
{
	size_t	start;
	size_t	end;

	start = *i;
	while (str[*i] && str[*i] != '$')
		(*i)++;
	end = *i;
	return (append_literal_str(result, str, start, end));
}

char	*expand_str(char *str)
{
	char	*result;
	size_t	i;

	if (!str)
		return (NULL);
	if (!ft_strchr(str, '$'))
		return (ft_strdup(str));
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result = process_literal_str(result, str, &i);
		if (!result)
			return (NULL);
		if (str[i] == '$')
		{
			result = append_variable_str(result, str, &i);
			if (!result)
				return (NULL);
		}
	}
	return (result);
}
