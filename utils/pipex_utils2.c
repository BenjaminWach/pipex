/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:45:06 by bwach             #+#    #+#             */
/*   Updated: 2024/01/22 03:11:14 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static size_t	ft_count_words(const char *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_word_mem(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_free_mem(char **split, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(split[j]);
		j++;
	}
	free (split);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	**split;
	size_t	len_word;

	split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s || !split)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			len_word = ft_word_mem(s, c);
			split[i] = ft_substr(s, 0, len_word);
			if (!split[i] && ft_free_mem(split, i) == NULL)
				return (NULL);
			s += len_word;
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
