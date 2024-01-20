/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:28 by bwach             #+#    #+#             */
/*   Updated: 2024/01/20 15:19:11 by bwach            ###   ########.fr       */
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

void	close_all_pipes(t_pxb *pb)
{
	size_t	i;

	i = -1;
	while (++i < (pb->nb_pipe))
	{
		close(pb->pipe[i]);
	}
}
