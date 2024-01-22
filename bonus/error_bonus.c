/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:19:18 by bwach             #+#    #+#             */
/*   Updated: 2024/01/22 09:17:16 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	file_error(char *err)
{
	perror(err);
	exit (0);
}

int	msg_error_bs(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

void	no_environment(t_pxb *p, int ac, char **av)
{
	printf("on est dans no-env");
	p->env_path = NULL;
	p->cmd_paths = NULL;
	write(2, "pipex: ", 7);
	write(2, av[2 + p->hdc - 1], ft_strlen(av[2 + p->hdc - 1]));
	write(2, ": command not found\n", 20);
	exit (0);
}
