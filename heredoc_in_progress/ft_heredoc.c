/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:33:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/29 08:59:41 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_is_eof(t_heredoc **heredoc, char **line)
{
	if (!*line)
	{
		free(*line);
		ft_free_list_heredoc(heredoc);
		return (1);
	}
	return (0);
}

int	ft_heredoc(t_env *env, t_heredoc **heredoc, char *eof, int quoted)
{
//	struct sigaction	action;
	char				*line;
	char				*tmp;

	line = NULL;
//	ft_set_sigaction(&action, 'm');
//	action.sa_handler = ft_main_handler;
//	signal(SIGQUIT, SIG_IGN);
//	sigaction(SIGINT, &action, NULL);
	line = readline(">");
	if (ft_is_eof(heredoc, &line))
		return (1);
	if (ft_strcomp(line, eof) == 0)
		return (1);
	if (ft_strlen(line) > 0)
	{
		if (!quoted)
			tmp = ft_interpret_dollar(env, line);
		else
			tmp = ft_str_copy_nofree(line);
		*heredoc = ft_eadd_tolist_heredoc(*heredoc, tmp);
	}
	if (line)
		free(line);
	return (0);
}
