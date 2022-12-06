#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define BUFFER_SIZE 1
char *get_next_line(int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	char store[100000];
	char buf;
	int y = 0;
	store[0] = '\0';
	while (read(fd, &buf, 1))
	{
		store[y] = buf;
		store[y + 1] = '\0';
		if (buf == '\n')
			break ;
		y++;
	}
	if (store[0] == '\0')
		return(NULL);
	char *copy;
	y = 0;
	while (store[y++]);
	copy = malloc(sizeof(char) * y + 1);
	y = -1;
	while (store[++y])
		copy[y] = store[y];
	copy[y] = '\0';
	return(copy);	
}

int main()
{
	int fd = open("new", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s", s);
	while (s)
	{
		s = get_next_line(fd);
		printf("%s", s);
	}
	
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", ft_strdup("hello\n"));
}