/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:24:54 by bwach             #+#    #+#             */
/*   Updated: 2024/01/10 13:22:18 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	name_prog(char **argv)
{
	char	*prog_name;

	prog_name = ft_strrchr(argv[0], '/') + 1;
	if (!prog_name || !*prog_name)
		prog_name = argv[0];
	write(2, prog_name, ft_strlen(prog_name));
}

int	msg_error(char *msg)
{
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	return (1);
}

void	error_quit(char *msg)
{
	perror(msg);
	exit(1);
}
