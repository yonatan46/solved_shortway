#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// # define BUFFER_SIZE 1 

/**
* prepare for the exam
*/
char *get_next_line(int fd)
{
    if (BUFFER_SIZE <= 0 || fd < 0) return(NULL);
    char *copy = malloc(sizeof(char) * 1000000), *tmp = copy;
    while (read(fd, tmp, 1)) if (*(tmp++) == '\n') break;
	*(tmp) = '\0';
    return (copy[0] == '\0' ? NULL: copy);
}

/**
* if u want to use calloc
*/
char *get_next_line(int fd)
{
    if (BUFFER_SIZE <= 0 || fd < 0) return(NULL);
    char *copy, *tmp;
    copy = calloc(sizeof(char), 100000);  
    tmp = copy;
    while (read(fd, tmp, 1)) if (*(tmp++) == '\n') break;
    return (copy[0] == '\0' ? NULL: copy);
}

// int main()
// {
//     int fd = open("new", O_RDONLY);
//     char *s = get_next_line(fd);
//     // while (s)
//     // {
//     //     printf("%s", s);
//     //     s = get_next_line(fd);
//     // }
//     // s = get_next_line(fd);
//     printf("%s", s);
//     s = get_next_line(fd);
//     printf("%s", s);
// }
