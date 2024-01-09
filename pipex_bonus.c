/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:46:28 by bwach             #+#    #+#             */
/*   Updated: 2024/01/09 13:36:45 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	setting_bonus_var(t_pipex *pipex, int argc, char **argv)
{
	if (access(argv[1], F_OK) == -1)
		error_quit(ERR_INFILE);
	if (pipe(pipex->tube) < 0)
		error_quit(ERR_PIPE);
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		error_quit(ERR_INFILE);
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
		error_quit(ERR_OUTFILE);
}

int	pipex_bonus(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int	nb_cmd;

	nb_cmd = 0;
	setting_bonus_var(&pipex, argc, argv);
	paths_to_cmd(&pipex, envp);
	while (nb_cmd <= argc - 3)
	{
		pipex->pid_child1 = fork();
		if (pipex->pid_child1 < 0)
			error_quit(ERR_FORK);
		if (pipex->pid_child1 == 0)
			first_son_bonus(&pipex, argv, nb_cmd);
		pipex->pid_child2 = fork();
		if (pipex->pid_child2 < 0)
			error_quit(ERR_FORK);
		if (pipex->pid_child2 == 0)
			second_son_bonus(&pipex, argv, nb_cmd);
	}
}

int	is_bonus(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc == 6)
	{
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
			return (1);
		else
			pipex_bonus(argc, argv, envp, pipex);
	}
	return (0);
}
