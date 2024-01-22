/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:16:23 by bwach             #+#    #+#             */
/*   Updated: 2024/01/22 11:15:10 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	init_vars(int ac, char **av, char **envp, t_pxb *pb)
{
	pb->id = -1;
	pb->status = 0;
	pb->nb_cmd = ac - 3 - (pb->hdc);
	pb->nb_pipe = 2 * (pb->nb_cmd - 1);
	pb->pipe = (int *)malloc(sizeof(int) * pb->nb_pipe);
	if (!pb->pipe)
		msg_error_bs(ERR_PIPE);
	pb->env_path = ft_path(envp, pb);
	pb->cmd_paths = ft_split(pb->env_path, ':');
	if (!pb->cmd_paths)
		free_pipe(pb);
}

static void	piping_cmd(t_pxb *pb)
{
	size_t	i;

	i = 0;
	while (i < (pb->nb_cmd))
	{
		pipe(pb->pipe + 2 * i);
		if (pipe < 0)
			free_path(pb);
		i++;
	}
}

char	*parse_cmd(char **path, char *flag)
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

int	main(int argc, char *argv[], char *envp[])
{
	t_pxb	pb;

	if (argc < is_heredoc(argv, &pb))
		return (msg_error_bs(ERR_INP));
	files_management(argc, argv, &pb);
	init_vars(argc, argv, envp, &pb);
	piping_cmd(&pb);
	while ((++pb.id) < (pb.nb_cmd))
		children(pb, argc, argv, envp);
	close_all_pipes(&pb);
	waitpid(-1, &pb.status, 0);
	if (WIFEXITED(pb.status))
		return (WEXITSTATUS(pb.status));
	free_path(&pb);
	return (pb.status);
}
