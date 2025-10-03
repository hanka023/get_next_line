
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	return (buf);
}

char	*join_buffer(char *buffer, int fd)
{
	char	*new_line;
	char	*tmp;
	char	*line;

	new_line = NULL;
	if(buffer)
		new_line = ft_strchr(buffer, '\n');
	if(new_line)
		return(buffer);

	while (new_line == NULL)
	{
		tmp = byte_read(fd);
		if (!tmp)
			break;
		if(buffer)
			line = ft_strjoin(buffer, tmp);
		else
			line = ft_strdup(tmp);
		free(buffer);
		free(tmp);
		buffer = line;
		// new_line = ft_strchr(line, '\n');
	}

		return(buffer);

}

char	*next_line(char *buffer)

{
	int i;
	int n;
	char *newline;

	i = 0;
	n = 0;
	if (!buffer|| buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	
	newline = malloc((sizeof(char)) * (i + 1));
	while (n < i)
	{
		newline[n] = buffer[n];
		++n;
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
		free(buffer);
		return (NULL);
	}
	start++;
	start2 = ft_strdup(start);
	free(buffer);
	return (start2);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char		*next;
	// char		*new_line;
	// int 	i;

	// i = 0;
	// new_line = NULL;
	// if(ft_strchr(buffer, '\n') != NULL)
	// {
	// 	while(buffer[i] !='\n')
	// 	{
	// 		new_line[i] = buffer[i];
	// 		i++;
	// 	}
	// 	new_line[i] = '\n';
	// 	i++;
	// 	new_line[i] = '\0';
	// 	return(new_line);
	// }

	buffer = join_buffer(buffer,fd);
	// printf("buffer %s\n", buffer);
	next = next_line(buffer);
	// printf("next %s\n", next);
	buffer = start_line(buffer);
	// printf("start %s\n", buffer);
	if(next)
		return(next);
	else
		return(NULL);

}







