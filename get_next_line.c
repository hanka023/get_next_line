
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
	{
		buf[n] = '\0'; // ← tady přidám ukončovací znak
	}
	/**************************test**************** */
	// printf("***********  buf = %s \n\n", buf);
	/**************************test**************** */
	return (buf);
}

char	*join_buffer(int fd)
{
	char		*new_line;
	static char	*buffer;
	char		*joined;
	char		*tmp;

	new_line = NULL;
	while (new_line == NULL)
	{
		// printf(" ------------------nove while ------------ \n\n");
		tmp = byte_read(fd);
		new_line = ft_strrchr(tmp, '\n');
		// printf("***********  tmp = %s \n\n", tmp);
		// printf(" ********* new_line = %s \n\n", new_line);
		// printf(" ********* buffer pred upravou  = %s \n\n", buffer);
		if (!buffer)
			buffer = ft_strdup(tmp); // první alokace
		else
		{
			joined = ft_strjoin(buffer, tmp);
			free(buffer);
			buffer = joined;
		}
		// printf(" ********* buffer posledni = %s \n\n", buffer);
	}
	// printf(" ********* buffer hotovy = %s \n\n", buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	int		n;
	char	*newline;
	char	*res;

	i = 0;
	n = 0;
	res = 0;
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

 static char *buffer;
char *line;
char *newline;
int l;
int n;



line = join_buffer(fd);
    if (!line)
        return (NULL);
l = (int)ft_strlen(line);
//printf(" *********  line = %s \n\n", line);

newline = get_next_line(fd);
	  if (!newline)
        return (NULL);
n = (int)ft_strlen(newline);


buffer = line;

//printf(" *res= = %s \n\n", line);
// printf(" *newline = %s \n\n", newline);
buffer[n] = '\0';

//free(line);

free(newline);
return(buffer);

}











