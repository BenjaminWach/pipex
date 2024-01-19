/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:58:31 by bwach             #+#    #+#             */
/*   Updated: 2024/01/19 14:44:35 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//libraries
# include "../inc/pipex.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>

//errors
# define ERR_ENV "Environment's error"
# define ERR_INF "Infile"
# define ERR_OUT "Outfile"
# define ERR_INP "Invalid number of arguments.\n"
# define ERR_PID "Fork's error"
# define ERR_CMD "Command not found: "
# define ERR_HDOC "Heredoc's error"
# define ERR_GNL "GNL 's error"

//structure
typedef struct s_pxb
{
	int		infile;
	int		outfile;
	int		hdc;
	int		pipe[2];
	int		id;
	pid_t	pid;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		nb_cmd;
	int		nb_pipe;
}				t_pxb;

//FUNCTIONS:
int		main(int argc, char *argv[], char *envp[]);

//here_doc
int		is_heredoc(char **av, t_pxb *pb);
void	here_doc(char *limiter, t_pxb *pb);

//paths
void	files_management(int ac, char **av, t_pxb *pb);
char	*ft_find_path(char **envp);

//error management
void	file_error(char *err);
int		msg_error(char *msg);
void	pipe_error(char *arg);

#endif