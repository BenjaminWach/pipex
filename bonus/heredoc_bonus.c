/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:35:28 by bwach             #+#    #+#             */
/*   Updated: 2024/01/18 15:38:05 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	heredoc_data(char **av, t_pxb *pb)
{
	char	*line;

	close(pb->pipe[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			msg_quit(ERR_HDOC);
		}
		write(pb->pipe[1], line, ft_strlen(line));
		write(pb->pipe[1], "\n", 1);
		free(line);
	}
}

void	here_doc(t_pxb *pb, char **av)
{
	pb->pid = fork();
	if (pb->pid == -1)
		exit (0);
	if (!pb->pid)
		heredoc_data(av, pb);
	else
	{
		close(pb->pipe[1]);
		dup2(pb->pipe[0], 0);
		wait(NULL);
	}
}
