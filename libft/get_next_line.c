/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:50:13 by akemalan          #+#    #+#             */
/*   Updated: 2025/08/27 22:22:51 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char *stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
	return (temp);
}

static char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	int		byte_read;

	if (!stash)
		stash = ft_calloc(1, 1);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		stash = ft_free(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*ft_next(char *stash)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stashes[OPEN_MAX];
	char		*line;

	if ((fd < 0) || (fd >= OPEN_MAX) || (BUFFER_SIZE <= 0))
		return (NULL);
	stashes[fd] = ft_read_file(fd, stashes[fd]);
	if (!stashes[fd])
		return (NULL);
	line = ft_line(stashes[fd]);
	stashes[fd] = ft_next(stashes[fd]);
	return (line);
}
