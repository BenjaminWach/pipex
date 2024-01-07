/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:19:50 by bwach             #+#    #+#             */
/*   Updated: 2024/01/05 02:52:15 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*fetch_command(char **path, char *flag)
{
	char	*tmp;
	char	*cmd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmd = ft_strjoin(tmp, flag);
		free(tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		path++;
	}
	return (NULL);
}

void	second_son(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], STDIN_FILENO);
	close(pipex.tube[1]);
	dup2(pipex.fd_out, STDOUT_FILENO);
	pipex.cmd_flags = ft_split(argv[3], ' ');
	pipex.cmd = fetch_command(pipex.cmd_paths, pipex.cmd_flags[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		msg_error(ERR_CMD);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_flags, envp) == -1)
		error_quit(ERR_EXE);
}

void	first_son(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], STDOUT_FILENO);
	close(pipex.tube[0]);
	dup2(pipex.fd_in, STDIN_FILENO);
	pipex.cmd_flags = ft_split(argv[2], ' ');
	pipex.cmd = fetch_command(pipex.cmd_paths, pipex.cmd_flags[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		msg_error(ERR_CMD);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_flags, envp) == -1)
		error_quit(ERR_EXE);
}
