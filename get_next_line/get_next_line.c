#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
// #define BUFFER_SIZE 1
char *get_next_line(int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	char store[100000];
	char buf;
	int rd = 1;
	int y = 0;
	store[0] = '\0';
	while (rd)
	{
		rd = read(fd, &buf, 1);
		if (rd == 0)
			break ;
		store[y] = buf;
		store[y + 1] = '\0';
		if (buf == '\n')
			break;		
		y++;
	}
	if (store[0] == '\0')
		return(NULL);	
	int x = 0;
	char *copy;
	while (store[x++]);
	copy = malloc(sizeof(char) * x + 1);
	x = -1;
	while (store[++x])
		copy[x] = store[x];
	copy[x] = '\0';
	return(copy);	
}

// int main()
// {
// 	int fd = open("new", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", ft_strdup("hello\n"));
// }