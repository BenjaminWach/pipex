/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:12:52 by bwach             #+#    #+#             */
/*   Updated: 2024/01/18 16:33:19 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	msg_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

void	msg_quit(char *msg)
{
	perror(msg);
	exit (1);
}
