/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:02:24 by bwach             #+#    #+#             */
/*   Updated: 2024/01/10 15:35:59 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	here_doc(t_bonus *pipexb, int ac, char **av, char **envp)
{
	char	*line;
	int		doc;

	doc = open(".tmp/here_doc.txt", O_CREAT | O_WRONLY | O_TRUNC | 0644);
	if (!doc)
		msg_error(ERR_HEREDOC);
	while (1)
	{
		line = get_next_line(doc);
		if (ft_strncmp(&line, av[2], ft_strlen(av[2])))
			break ;
	}
	
}
