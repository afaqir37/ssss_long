#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
char *get_next_line(int fd);
int main()
{
   int fd = open("maps/map1.ber", O_RDONLY);
   printf("%s", get_next_line(fd));
   printf("%s", get_next_line(fd));
}