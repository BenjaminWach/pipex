/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:58:31 by bwach             #+#    #+#             */
/*   Updated: 2024/01/18 16:23:38 by bwach            ###   ########.fr       */
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

//structure
typedef struct s_pxb
{
	int		infile;
	int		outfile;
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

//functions

int		main(int argc, char *argv[], char *envp[]);
int		open_file(char *file, int in_out);
void	piping(t_pxb *pb, char *cmd, char **envp);
void	exec_cmd(t_pxb *pb, char *cmd, char **envp);

void	here_doc(t_pxb *pb, char **av);
void	heredoc_data(char **av, t_pxb *pb);

void	free_parent_bs(t_pxb *pb);
void	free_child_bs(t_pxb *pb);

int		msg_error(char *msg);
void	msg_quit(char *msg);

#endif