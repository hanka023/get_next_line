
#include <fcntl.h>   // open()
#include <unistd.h>  // read(), close()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()
#include "get_next_line.h"


// char *get_next_line(int fd)
// {
// 	char *buf;

// 	static char *buffer = NULL;
// 	ssize_t n;
// 	char *tmp;

// 	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	n = read(fd, buf, BUFFER_SIZE);
// 	if (n <= 0)
// 			return NULL;
// 	else if (n > 0)
// 	{
// 		buf[n] = '\0';   // ← tady přidám ukončovací znak
// 	}

// 	if (buffer == NULL)           // ← první volání
// 			tmp = ft_strdup(buf);
// 	else
// 	tmp = ft_strjoin(buffer, buf);
// 	free(buffer);
// 	buffer = tmp;

// 	return (tmp);
// }


