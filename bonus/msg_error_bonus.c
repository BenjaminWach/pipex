/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:22:05 by bwach             #+#    #+#             */
/*   Updated: 2024/01/16 20:25:37 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	msg(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	msg_pipe(char *msg)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	error_quit(char *error)
{
	perror(error);
	exit(1);
}
