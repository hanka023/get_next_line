
#include <fcntl.h>   // open()
#include <unistd.h>  // read(), close()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    // otevřu soubor
    fd = open("text2.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }

    //čtu po řádcích, dokud get_next_line nevrátí NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);  // vypíšu řádku
        free(line);          // MUSÍM uvolnit paměť!
    }

    close(fd);
    return (0);
}
