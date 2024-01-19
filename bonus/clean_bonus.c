/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:28 by bwach             #+#    #+#             */
/*   Updated: 2024/01/19 14:57:24 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	free_path(t_pxb *pb)
{
	size_t	i;

	i = -1;
	while (pb->cmd_paths[++i])
	{
		free(pb->cmd_paths[i]);
	}
	free(pb->cmd_paths);
}
