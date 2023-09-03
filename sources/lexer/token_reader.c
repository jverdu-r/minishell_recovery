/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:46:24 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/06/22 19:43:52 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

t_token	check_token(char *tk, int i)
{
	if (tk[i] == '|')
		return (PIPE);
	if (tk[i] == '<')
	{
		if (tk[i + 1] == '<')
			return (LESS_LESS);
		else
			return (LESS);
	}
	if (tk[i] == '>')
	{
		if (tk[i + 1] == '>')
			return (GREAT_GREAT);
		else
			return (GREAT);
	}
	return (0);
}

int	read_words(char *args, int i, t_lexer **list)
{
	int	j;
	int	qt;

	j = 0;
	(void)list;
	while (args[i + j])
	{
		if (args[i + j] == '\'' || args[i + j] == '\"')
		{
			qt = i + j;
			j++;
			while (args[i + j] != args[qt])
				j++;
		}
		if (is_white_space(args[i + j]) || check_token(args, i + j))
			break;
		else
			j++;
	}
	lexer_addback(list, lexer_new(ft_substr(args, i, j), 0));
	if (!list)
		return (-1);
	return (j);
}

int	token_reader(t_toolbox *tools)
{
	t_token	tk;
	int		i;
	int		j;

	i = 0;
	while (tools->args[i])
	{
		j = 0;
		if (is_white_space(tools->args[i]))
			i++;
		if (check_token(tools->args, i))
		{
			tk = token_handler(tools, i);
			if (tk == LESS_LESS || tk == GREAT_GREAT)
				j += 2;
			else
				j++;
		}
		else
			j += read_words(tools->args, i, &tools->lexer_list);
		i += j;
	}
	return (1);
}
