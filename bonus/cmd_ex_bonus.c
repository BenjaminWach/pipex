/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:07:35 by bwach             #+#    #+#             */
/*   Updated: 2024/01/18 16:30:24 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static char	**fetch_cmd(t_pxb *pb, char *cmd, char **envp)
{
	int		i;
	char	*command;

	i = 0;
	pb->env_path = find_path(envp);
	pb->cmd_paths = ft_split(pb->env_path, ':');
	pb->cmd_args = ft_split(cmd, ' ');
	while (pb->cmd_paths[i])
	{
		pb->cmd = ft_strjoin(pb->cmd_paths[i], "/");
		command = ft_strjoin(pb->cmd, pb->cmd_args[0]);
		free(pb->cmd);
		if (access(command, F_OK | X_OK) == 0)
		{
			free_child_bs(pb);
			return (command);
		}
		free(command);
		i++;
	}
	return (NULL);
}

void	exec_cmd(t_pxb *pb, char *cmd, char **envp)
{
	pb->cmd_args = ft_split(cmd, ' ');
	pb->cmd_paths = fetch_cmd(&pb, pb->cmd_args[0], envp);
	if (execve(pb->cmd_paths, pb->cmd_args, envp) == -1)
	{
		free_child_bs(pb->cmd_args);
		msg_quit(ERR_CMD);
	}
}
