
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
	printf("buf %s\n\n", buf);
	return (buf);
}

char	*join_buffer(int fd)
{
	char		*new_line;
	char		*joined;
	char		*tmp;

	new_line = NULL;
	while (new_line == NULL)
	{
		tmp = byte_read(fd);
		new_line = ft_strrchr(tmp, '\n');
		if (!joined)
			joined = ft_strdup(tmp);
		else
		{
			joined = ft_strjoin(joined, tmp);
		}
	}
	printf("joined %s\n\n", joined);
	return (joined);
}

char	*next_line(int fd)

{
	char	*line;
	int		i;
	int		n;
	char	*newline;

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


char *start_line(int fd)
{
	char	*start;
	char	*longline;
	// int		i;
	// int		j;

	// i = 0;
	// j = 0;


	size_t len;
char *x;


	start = next_line(fd);
	if (!start)
    	return NULL;
	longline = join_buffer(fd);
	if (!longline)
    	return start;


	len = ft_strlen(longline);
printf("novy radek %s\n\n", start);
printf("dlouhy radek %s\n\n", longline);

	// while (start[i] != '\0')
	// {
	// 	i++;
	// 	j++;
	// }
	// i = 0;
	// while (longline[j] !='\0')
	// {
	// 	start[i] = longline[j];
	// 	++i;
	// 	++j;
	// }
	//free(longline);

x = ft_strnstr(longline, '\0', len);
printf("xxxx %s\n\n", x);
	return(start);
}













