
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>   // open()
#include <unistd.h>  // read(), close()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif



/*  utils */
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	*ft_calloc(size_t count, size_t size);



/***************************************** */
char	*byte_read(int fd);

char	extract_line(char **buffer);

char	*join_buffer(int fd);


char	*get_next_line(int fd);

char *start_line(int fd);




#endif
