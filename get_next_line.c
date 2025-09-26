
#include "get_next_line.h"
#include <fcntl.h>  // open()
#include <stdio.h>  // printf()
#include <stdlib.h> // exit()
#include <unistd.h> // read(), close()

char	*byte_read(int fd)
{
	char	*buf;
	ssize_t	n;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	if (n <= 0)
	{
		free(buf);
		return (NULL);
	}
	else if (n > 0)
		buf[n] = '\0';
	return (buf);
}

char	*join_buffer(int fd)
{
	char	*new_line;
	char	*joined;
	char	*tmp;
	char	*new;

	new_line = NULL;
	joined = NULL;
	new = NULL;
	while (new_line == NULL)
	{
		tmp = byte_read(fd);
		if (!tmp) // konec souboru
			break ;
		new_line = ft_strrchr(tmp, '\n');
		if (!joined)
			joined = ft_strdup(tmp);
		else
		{
			new = ft_strjoin(joined, tmp);
			free(joined);
			joined = new;
		}
		free(tmp);
	}
	return (joined);
}

char	*next_line(int fd)

{
	char *line;
	int i;
	int n;
	char *newline;

	i = 0;
	n = 0;
	line = join_buffer(fd);
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	newline = malloc((sizeof(char)) * (i + 1));
	while (n < i)
	{
		newline[n] = line[n];
		++n;
	}
	newline[n] = '\0';
	return (newline);
}

char	*start_line(int fd)
{
	char	*longline;
	char	*start;
	char	*start2;

	longline = join_buffer(fd);
	if (!longline)
		return (NULL);
	start = ft_strrchr(longline, '\n');
	if (!start)
	{
		free(longline);
		return (NULL);
	}
	// start = start + 1;  //pouze pokud chci preskocit '\n'
	start2 = ft_strdup(start);
	free(longline);
	free(start);
	printf("start line : %s\n", start2);
	return (start2);
}
