
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
		//printf("tmp: %s\n", tmp);
		if (!tmp)
			break;
		//printf("buffer před join: %s\n", buffer ? buffer : "(null)");
		if(buffer)
			line = ft_strjoin(buffer, tmp);
		else
			line = ft_strdup(tmp);
		//printf("line po join: %s\n", line);

		free(buffer); //?????????
		free(tmp);
		buffer = line;

		new_line = ft_strchr(line, '\n');

	}

// printf("budffer na konci join buffer: %s\n", buffer);
// 		printf("linena konci: %s\n", line);

		return(buffer);

}

char	*next_line(char *buffer)

{
	int i;
	int n;
	char *line;

	i = 0;
	n = 0;
//printf("budffer v nextline: %s\n", buffer);

	if (!buffer || buffer[0] == '\0')
		return (NULL);

	while (buffer[i] != '\n' && buffer[i] != '\0' )
		i++;

	if (buffer[i] == '\n')
		line = malloc((sizeof(char)) * (i + 2));
	else
		line = malloc((sizeof(char)) * (i + 1));
	if (!line)
        return (NULL);
	while (buffer[n] && (n <= i))
	{
		line[n] = buffer[n];
		++n;
	}

	line[n] = '\0';
//printf("-------line v nextline: %s\n", line);
	return (line);

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
	if (!start || start == NULL)
	{
		free(buffer);
		return (NULL);
	}


	// start++; ????

	 start2 = ft_strdup(start);
//free(start); //?????

	free(buffer);
buffer = start2;
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char		*next;



	buffer = join_buffer(buffer,fd);
	//printf("buffer pred nextline:	 %s\n", buffer);
	next = next_line(buffer);
	//printf("next %s\n", next);
	buffer = start_line(buffer);
	//printf("start %s\n", buffer);




	if(next)
		return(next);
	else
		return(NULL);

}








