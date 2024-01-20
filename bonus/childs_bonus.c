/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:03:33 by bwach             #+#    #+#             */
/*   Updated: 2024/01/20 14:33:58 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	redirection(int stdin, int stdout)
{
	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
}

void	children(t_pxb pb, int ac, char **av, char **env)
{
	pb.pid = fork();
	if (!pb.pid)
	{
		if (pb.id == 0)
			redirection(pb.infile, pb.pipe[1]);
		else if (pb.id == pb.nb_cmd - 1)
			redirection(pb.pipe[2 * pb.id - 2], pb.outfile);
		else
			redirection(pb.pipe[2 * pb.id - 2], pb.pipe[2 * pb.id + 1]);
		close_all_pipes(&pb);
		pb.cmd_args = ft_split(av[2 + pb.hdc + pb.id], ' ');
		pb.cmd = parse_cmd(pb.cmd_paths, pb.cmd_args[0]);
		if (!pb.cmd)
		{
			write(2, ERR_CMD, ft_strlen(ERR_CMD));
			ft_putendl_fd(pb.cmd_args[0], 2);
			free_path(&pb);
			if (pb.id == (ac - 1))
				exit(127);
			exit(1);
		}
		if (execve(pb.cmd, pb.cmd_args, env) == -1)
			msg_error(ERR_EXE);
	}
}
