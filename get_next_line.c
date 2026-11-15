/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkyawh <hkyawh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:17:14 by hkyawh            #+#    #+#             */
/*   Updated: 2026/11/15 22:06:10 by hkyawh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *stash)
{
	int	i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		return (ft_substr(stash, 0, i + 1));
	else
		return (ft_substr(stash, 0, i));
}

static char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	return (new_stash);
}

static char	*fill_stash(int fd, char *stash, char *buff)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = '\0';
		if (!stash)
		{
			stash = malloc(1);
			if (stash)
				stash[0] = '\0';
		}
		temp = str_join(stash, buff);
		free(stash);
		stash = temp;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	stash = fill_stash(fd, stash, buff);
	free(buff);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = set_line(stash);
	stash = clean_stash(stash);
	return (line);
}
