/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:38 by bwach             #+#    #+#             */
/*   Updated: 2024/01/08 14:11:31 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	get_input_doc(t_pipex *pipex, char **argv)
{
	limiter = argv[2];
	stck;
	while
		write (>)
		get_next_line(0);
			if (null , line == limiter - 1, line != '\n', limiter != vide && !limiter/line[0] != '\n')
				break;
		
}

void	ft_here_doc(char **argv, t_pipex *pipex)
{
	char	*line;

	line = get_input_doc(pipex, argv);
	if (!line)
		error_quit(ERR_INPUT);
	pipex->fd_bonus = open("/tmp/.pipex_here_doc", O_WRONLY
		| O_CREAT | O_TRUNC | 0644);
	
}