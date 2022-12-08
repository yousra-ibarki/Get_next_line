#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 100

char *get_next_line(int fd)
{
	static char *hold;
	char *buffer; 
	int nb = 0;
	int i = 0; 
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buffer)
		return NULL;
	hold = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!hold)
		return NULL;
	buffer[BUFFER_SIZE] = '\0';
	nb = read(fd, buffer, BUFFER_SIZE);
	while(hold[i])
	{ 	
		if(hold[i] == '\n')
		i++;
	}
	strcpy(hold, buffer);
	return hold;
}
int main()
{
	int fd = 0;
	char *str;
	fd = open("txt", O_CREAT | O_RDWR, 777);
	str = get_next_line(fd);
	while (str)
	{
		str = get_next_line(fd);
	}

	printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
}