/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:21:36 by bwach             #+#    #+#             */
/*   Updated: 2024/01/08 15:02:33 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	setting_variables(t_pipex *pipex, int argc, char **argv)
{
	if (access(argv[1], F_OK) == -1)
		error_quit(ERR_INFILE);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		ft_here_doc(argv, &pipex);
	if (pipe(pipex->tube) < 0)
		error_quit(ERR_PIPE);
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		error_quit(ERR_INFILE);
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
		error_quit(ERR_OUTFILE);
}

static char	*ft_find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	msg_error(ERR_PATH);
	return (NULL);
}

static void	paths_to_cmd(t_pipex *pipex, char **envp)
{
	pipex->paths = ft_find_path(envp);
	pipex->cmd_paths = ft_split(pipex->paths, ':');
}

//close the reading end and writing end:
static void	exit_pipe(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

//valided, find path, split path, fork, dup2, execve, delay the excut, free..
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5 || is_bonus(argc, argv) == 1)
		return (msg_error(ERR_INPUT));
	if (argv[1] == NULL || argv[argc - 1] == NULL)
		return (msg_error(ERR_INPUT));
	setting_variables(&pipex, argc, argv);
	paths_to_cmd(&pipex, envp);
	pipex.pid_child1 = fork();
	if (pipex.pid_child1 == 0)
		first_son(pipex, argv, envp);
	pipex.pid_child2 = fork();
	if (pipex.pid_child2 == 0)
		second_son(pipex, argv, envp);
	exit_pipe(&pipex);
	waitpid(pipex.pid_child1, NULL, 0);
	waitpid(pipex.pid_child2, NULL, 0);
	free_parent(&pipex);
	return (EXIT_SUCCESS);
}
