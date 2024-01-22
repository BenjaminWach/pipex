/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:33:22 by bwach             #+#    #+#             */
/*   Updated: 2024/01/22 03:57:39 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	*ft_path(char **envp, t_pxb *pb)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
		i++;
	}
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
		{
			write(pb->outfile, "       0\n", 9);
			file_error("pipex: input");
		}
	}
}

static void	get_outfile(int ac, char *av, t_pxb *pb)
{
	if (pb->hdc)
		pb->outfile = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pb->outfile = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pb->outfile < 0)
		file_error("pipex: output");
}

void	files_management(int ac, char **av, t_pxb *pb)
{
	get_outfile(ac, av[ac - 1], pb);
	get_infile(ac, av, pb);
}
