/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:03:33 by bwach             #+#    #+#             */
/*   Updated: 2024/01/22 04:11:22 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	redirection(int stdin, int stdout)
{
	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
}

static void	no_cmd_msg(t_pxb *p)
{
	write(2, "pipex: ", 7);
	write(2, p->cmd_args[0], ft_strlen(p->cmd_args[0]));
	write(2, ": command not found\n", 20);
}

void	children(t_pxb p, int ac, char **av, char **env)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.id == 0)
			redirection(p.infile, p.pipe[1]);
		else if (p.id == p.nb_cmd - 1)
			redirection(p.pipe[2 * p.id - 2], p.outfile);
		else
			redirection(p.pipe[2 * p.id - 2], p.pipe[2 * p.id + 1]);
		close_all_pipes(&p);
		p.cmd_args = ft_split(av[2 + p.hdc + p.id], ' ');
		p.cmd = parse_cmd(p.cmd_paths, p.cmd_args[0]);
		if (!p.cmd)
		{
			no_cmd_msg(&p);
			free_path(&p);
			if (p.id == (p.nb_cmd - 1))
				exit(127);
			exit(0);
		}
		if (execve(p.cmd, p.cmd_args, env) == -1)
			msg_error_bs(ERR_CMD);
	}
}
