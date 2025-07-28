/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:34 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:34 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_redir_char(char c)
{
	return (c == '<' || c == '>');
}

int	is_op_char(char c)
{
	return (c == '|' || is_redir_char(c));
}

int	is_quote_char(char c)
{
	return (c == '\'' || c == '"');
}

int	is_whitespaces(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_meta_char(char c)
{
	return (is_whitespaces(c) || is_op_char(c) || is_quote_char(c));
}
