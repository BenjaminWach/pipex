/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:16:23 by bwach             #+#    #+#             */
/*   Updated: 2024/01/19 14:57:35 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	init_vars(int ac, char **av, char **envp, t_pxb *pb)
{
	pb->nb_cmd = ac - 3 - (pb->hdc);
	pb->nb_pipe = 2 * (pb->nb_cmd - 1);
	pb->pipe = (int *)malloc(sizeof(int) * pb->nb_pipe);
	if (!pb->pipe)
		msg_error(ERR_PIPE);
	pb->env_path = ft_path(envp);
	pb->cmd_paths = ft_split(pb->env_path, ':');
	if (!pb->cmd_paths)
		free_paths(&pb);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pxb	pb;

	if (argc < is_heredoc(argv[1], &pb))
		return (msg_error(ERR_INP));
	files_management(argc, argv, &pb);
	init_vars(argc, argv, envp, &pb);
}
