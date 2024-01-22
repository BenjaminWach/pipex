/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:24:54 by bwach             #+#    #+#             */
/*   Updated: 2024/01/21 18:06:39 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	msg_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

void	error_quit(char *msg)
{
	perror(msg);
	exit(1);
}
