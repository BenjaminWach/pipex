/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:50:35 by bwach             #+#    #+#             */
/*   Updated: 2024/01/16 23:04:38 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	settings_bonus_var(t_bonus *pipexb, int ac, char **av, char **envp)
{
	if (ft_strncmp(av[1], "here_doc", 9))
		here_doc(&pipexb, ac, av, envp);
	else
	{
		if (access(av[1], F_OK) == -1)
			error_quit(ERR_INFILE);
		if (pipe(pipexb->tube) < 0)
			error_quit(ERR_PIPE);
		pipexb->fd_in = open(av[1], O_RDONLY);
		if (pipexb->fd_in < 0)
			error_quit(ERR_INFILE);
		pipexb->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipexb->fd_out < 0)
			error_quit(ERR_OUTFILE);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_bonus	*pipexb;

	if (ac != 5 || ac < 6 || !ft_strncmp(av[1], "here_doc", 9))
		msg_error(ERR_INPUT);
	settings_bonus_vars(&pipexb, ac, av, envp);
	
}