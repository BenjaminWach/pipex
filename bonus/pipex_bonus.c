/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:58:09 by bwach             #+#    #+#             */
/*   Updated: 2024/01/18 16:28:51 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pxb	pipexb;
	int		i;

	if (argc < 5)
		return (msg_error(ERR_INP));
	if (ft_strncmp(argv[1], "here_doc", 9))
	{
		if (argc < 6)
			return (msg_error(ERR_INP));
		i = 3;
		pipexb.infile = open_file(argv[argc - 1], 2);
		here_doc(&pipexb, argv);
	}
	else
	{
		i = 2;
		pipexb.infile = open_file(argv[1], 0);
		pipexb.outfile = open_file(argv[argc - 1], 1);
		dup2(pipexb.infile, 0);
	}
	while (i < argc -2)
		piping(&pipexb, argv[i++], envp);
	dup2(pipexb.outfile, 1);
	exec_cmd(&pipexb, argv[argc - 2], envp);
	free_parent_bs(&pipexb);
}
