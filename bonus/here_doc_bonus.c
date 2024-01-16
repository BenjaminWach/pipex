/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:02:24 by bwach             #+#    #+#             */
/*   Updated: 2024/01/16 23:04:31 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	here_doc(t_bonus *pipexb, int ac, char **av, char **envp)
{
	char	*line;
	int		doc;

	doc = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC | 0644);
	if (doc < 0)
		msg_error(ERR_HEREDOC);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(doc);
		if (!line)
			exit(1);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		if (ft_strncmp(line, av[2], ft_strlen((av[2]) + 1)))
			break ;
		free (line);
	}
	close(doc);
	pipexb->fd_in = open(".heredoc_tmp", O_RDONLY);
	if (pipexb->fd_in < 0)
	{
		unlink(".heredoc_tmp");
		error_quit(ERR_HEREDOC);
	}
	unlink(".heredoc_tmp");
}
