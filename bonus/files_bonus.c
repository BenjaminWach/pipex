/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:33:22 by bwach             #+#    #+#             */
/*   Updated: 2024/01/19 14:42:36 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	*ft_path(char **envp)
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

static void	get_infile(int ac, char **av, t_pxb *pb)
{
	if (!ft_strncmp("here_doc", av[1], 9))
		here_doc(av[2], pb);
	else
	{
		pb->infile = open(av[1], O_RDONLY);
		if (pb->infile < 0)
			file_error("pipex (infile)");
	}
}

static void	get_outfile(int ac, char **av, t_pxb *pb)
{
	if (pb->hdc)
		pb->outfile = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pb->outfile = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pb->outfile < 0)
		file_error("pipex (outfile)");
}

void	files_management(int ac, char **av, t_pxb *pb)
{
	get_infile(ac, av, &pb);
	get_outfile(ac, av, &pb);
}
