/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/10/07 00:07:55 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*byte_read(int fd, char **buffer)
{
	char	*buf;
	ssize_t	n;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	if (n < 0)
	{
		free(buf);
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	if (n == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[n] = '\0';
	return (buf);
}

char	*join_buffer(char *buffer, int fd)
{
	char	*new_line;
	char	*tmp;
	char	*line;

	new_line = NULL;
	if (buffer)
		new_line = ft_strchr (buffer, '\n');
	if (new_line)
		return (buffer);
	while (new_line == NULL)
	{
		tmp = byte_read(fd, &buffer);
		if (!tmp)
			break ;
		if (buffer)
			line = ft_strjoin(buffer, tmp);
		else
			line = ft_strdup(tmp);
		free (buffer);
		free (tmp);
		buffer = line;
		new_line = ft_strchr (line, '\n');
	}
	return (buffer);
}

char	*next_line(char *buffer)
{
	int		i;
	int		n;
	char	*newline;

	i = 0;
	n = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		++i;
	newline = malloc ((sizeof(char)) * (i + 1));
	while (n < i)
	{
		newline[n] = buffer[n];
		n++;
	}
	newline[n] = '\0';
	return (newline);
}

char	*start_line(char *buffer)
{
	char	*start;
	char	*start2;

	start = NULL;
	start2 = NULL;
	if (!buffer)
		return (NULL);
	start = ft_strchr(buffer, '\n');
	if (!start)
	{
		free (buffer);
		return (NULL);
	}
	start++;
	start2 = ft_strdup(start);
	free (buffer);
	return (start2);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free (buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = join_buffer (buffer, fd);
	if (!buffer)
		return (NULL);
	next = next_line (buffer);
	buffer = start_line (buffer);
	if (next)
		return (next);
	else
		return (NULL);
}
