/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:46:28 by bwach             #+#    #+#             */
/*   Updated: 2024/01/07 17:28:35 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_bonus(int argc, char **argv)
{
	if (argc == 6)
	{
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
			return (1);
		else
			error_quit(ERR_INPUT);
	}
	else
		error_quit(ERR_INPUT);
	return (0);
}
