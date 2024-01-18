/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:53:49 by bwach             #+#    #+#             */
/*   Updated: 2024/01/18 16:07:03 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	piping(t_pxb *pb, char *cmd, char **envp)
{
	if (pipe(pb->pipe) == -1)
		msg_quit(ERR_PIPE);
	pb->pid = fork();
	if (pb->pid == -1)
		msg_quit(ERR_PID);
	if (!pb->pid)
	{
		close(pb->pipe[0]);
		dup2(pb->pipe[1], 1);
		exec_cmd(pb, cmd, envp);
	}
	else
	{
		close(pb->pipe[1]);
		dup2(pb->pipe[0], 0);
	}
}
