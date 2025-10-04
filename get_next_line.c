
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
	buf[n] = '\0'; 
	// printf("buf >%s<",buf);
	return (buf);
}

char	*join_buffer(char *buffer, int fd)
{
	char	*new_line;
	char	*tmp;
	char	*line;
	char	*line2;

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
			line2 = ft_strjoin(line, tmp);
		else
			line = ft_strdup(tmp);
		
		printf("buffer uprostred join:>%s<", buffer);
		free(line);

		//free(buffer);
		free(tmp);
		//buffer = ft_strdup(line);
		
	
		new_line = ft_strchr(line, '\n');
		free(line);
	}
		printf("buffer na konci join:>>>%s<<<", buffer);

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
		++i;
	
	newline = malloc((sizeof(char)) * (i + 1));
	while (n < i)
	{
		newline[n] = buffer[n];
		n++;
	}
		newline[n] = '\0';
//printf("next line:>>>%s<<<", newline);
	return (newline);
}

char	*start_line(char *buffer)
{
	char	*start;
	char	*start2;
	char	len;

	len = 0;
	start = NULL;
	start2 = NULL;

	if (!buffer)
		return (NULL);

	//printf("buffer na zacatku startline:	 %s\n", buffer);

	start = ft_strchr(buffer, '\n');

	if (!start)
	{
		free(buffer);
		return (NULL);
	}

	start++;

	start2 = ft_strdup(start);
	free(buffer);
	buffer = ft_strdup(start2);
	free(start2);
	//printf("startline:	 >>>%s<<<", buffer);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char		*line;

	if (fd < 0 )
	{
   		return (NULL);
	}

	buffer = join_buffer(buffer,fd);
	//printf("join_buffer %s...", buffer);
	if (!buffer)
		return (NULL);
	line = next_line(buffer);
	//printf("next %s...", next);

	buffer = start_line(buffer);
	//printf("start %s...", buffer);
	if(line)
		return(line);
	else
		return(NULL);

}
