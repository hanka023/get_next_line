
#include <fcntl.h>   // open()
#include <unistd.h>  // read(), close()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()
#include "get_next_line.h"



int main(void)
{
    int     fd;
   char *ch;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }

ch = start_line(fd);

printf("start line %s", ch);
  free(ch);
return (0);
}
