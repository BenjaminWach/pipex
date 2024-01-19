/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:15:58 by bwach             #+#    #+#             */
/*   Updated: 2024/01/19 13:48:14 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;

	d = (unsigned char *)b;
	while (len--)
		d[len] = (unsigned char)c;
	return (b);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			temp = s;
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return ((char *)temp);
}
