/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:22:09 by bwach             #+#    #+#             */
/*   Updated: 2024/01/21 23:33:24 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

//strerror():
# include <string.h>

//perror():
# include <stdio.h>

//Waitpid(), wait():
# include <sys/wait.h>

//Process ID Type:
# include <sys/types.h>

//Input/Output: open, close, etc...
# include <sys/uio.h>

# define ERR_INPUT "Invalid numbers of arguments\n"
# define ERR_INFILE "Infile error\n"
# define ERR_OUTFILE "Outfile error\n"
# define ERR_CMD "command not found"
# define ERR_ENVP "Environment"
# define ERR_PIPE "Pipe error\n"
# define ERR_PATH "Path not found\n"
# define ERR_EXE "Execve failed\n"
# define ERR_FORK "Fork failed\n"

typedef struct s_pipex
{
	pid_t	pid_child1;
	pid_t	pid_child2;
	int		tube[2];
	int		fd_in;
	int		fd_out;
	char	*cmd;
	char	**cmd_flags;
	char	*paths;
	char	**cmd_paths;
}	t_pipex;

//main
int		main(int argc, char **argv, char **envp);

//parse
char	*ft_find_path(char **envp);
void	paths_to_cmd(t_pipex *pipex, char **envp);
void	exit_pipe(t_pipex *pipex);

//forks:
void	first_son(t_pipex pipex, char **argv, char **envp);
void	second_son(t_pipex pipex, char **argv, char **envp);

//utils
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
char	*ft_substr(char *str, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strrchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

//GNL
char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_memset_gnl(void *b, int c, size_t len);

//error managements:
int		msg_error(char *msg);
void	error_quit(char *msg);

//clean the memory:
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);

#endif