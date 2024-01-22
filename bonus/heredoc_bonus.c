/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:26:33 by bwach             #+#    #+#             */
/*   Updated: 2024/01/22 11:12:28 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	is_heredoc(char **av, t_pxb *pb)
{
	int	nb_arg;

	if (av[1] && !ft_strncmp("here_doc", av[1], 9))
	{
		pb->hdc = 1;
		nb_arg = 6;
		return (nb_arg);
	}
	else
	{
		pb->hdc = 0;
		nb_arg = 5;
		return (nb_arg);
	}
}

void	here_doc(char *limiter, t_pxb *pb)
{
	int		doc;
	char	*line;

	doc = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (doc < 0)
		file_error(ERR_HDOC);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (line < 0)
			msg_error_bs(ERR_GNL);
		if (!ft_strncmp(limiter, line, ft_strlen(limiter)))
			break ;
		write(doc, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(doc);
	pb->infile = open(".here_doc", O_RDONLY);
	if (pb->infile < 0)
	{
		unlink(".here_doc");
		file_error("pipex (heredoc)");
	}
}
