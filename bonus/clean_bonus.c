/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:28 by bwach             #+#    #+#             */
/*   Updated: 2024/01/22 04:08:14 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	free_path(t_pxb *pb)
{
	size_t	i;

	i = -1;
	close(pb->infile);
	close(pb->outfile);
	if (pb->hdc)
		unlink(".here_doc");
	while (pb->cmd_paths[++i])
	{
		free(pb->cmd_paths[i]);
	}
	free(pb->cmd_paths);
	free(pb->pipe);
}

void	free_cmds(t_pxb *pb)
{
	size_t	i;

	i = -1;
	while (pb->cmd_args[++i])
	{
		free(pb->cmd_args[i]);
	}
	free(pb->cmd_args);
	free(pb->cmd);
}

void	free_pipe(t_pxb *pb)
{
	close(pb->infile);
	close(pb->outfile);
	if (pb->hdc)
		unlink(".heredoc_tmp");
	free(pb->pipe);
	msg_error_bs(ERR_ENVP);
	exit(1);
}

void	close_all_pipes(t_pxb *pb)
{
	size_t	i;

	i = -1;
	while (++i < (pb->nb_pipe))
	{
		close(pb->pipe[i]);
	}
}
