/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:19:11 by bwach             #+#    #+#             */
/*   Updated: 2024/01/18 16:02:37 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	free_child_bs(t_pxb *pb)
{
	size_t	i;

	i = 0;
	while (pb->cmd_args[i])
	{
		free(pb->cmd_args[i]);
		i++;
	}
	free(pb->cmd_args);
	free(pb->cmd);
}

void	free_parent_bs(t_pxb *pb)
{
	size_t	i;

	i = 0;
	close(pb->infile);
	close(pb->outfile);
	while (pb->cmd_paths[i])
	{
		free(pb->cmd_paths[i]);
		i++;
	}
	free(pb->cmd_paths);
	free(pb->pipe);
}
