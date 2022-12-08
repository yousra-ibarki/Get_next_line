#include "get_next_line.h"

char *ft_getline(char *hold)
{
	int i = 0;
	char *holdline;
	if(!hold)
	return 0;
	while(hold[i] && hold[i] != '\n')
	i++;
	holdline = malloc(sizeof(char) * (i + 2));
	if(!holdline)
	return NULL;
	return ft_cpy(holdline, hold);
}

char *ft_nextone(char *hold)
{
	int i = 0;
	int k = 0;
	int len = ft_strlen(hold);
	char *nextone;
	if(!hold)
		return 0;
	while(hold[i] && hold[i] != '\0')
		i++;
	nextone = malloc(sizeof(char) * (len - i) + 1);
	if(!nextone)
	return 0;
	while(hold[i])
	{
		nextone[k] = hold[i];
		i++;
		k++;
	}
	nextone[k] = '\n';
	free(hold);
	return nextone;
	
}

char *get_next_line(int fd)
{
	static char *hold;
	char *buffer;
	char *holdline; 
	int nbb = 0;
	int i = 0;
	if(fd < 0 || BUFFER_SIZE < 1)
	return 0;
	while(!ft_backslash(hold) && hold[i] != '\n')
	{
	printf("hello world\n");
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if(!buffer)
			return NULL;
	nbb = read(fd, buffer, BUFFER_SIZE);
	if(nbb < 0)
	{
		free(buffer);
		return 0;
	}
	}
	buffer[nbb] = '\0';
	hold = ft_strjoin(hold, buffer);
	if(!hold)
	{
		if(buffer)
		free(buffer);
		hold = NULL;
		return NULL;
	}
	if(hold)
		holdline = ft_getline(hold);
		hold = ft_nextone(hold);
		return holdline;
}

int main()
{
	int fd = 0;
	char *str;
	fd = open("txt", O_CREAT | O_RDWR, 777);
	str = get_next_line(fd);
	//while (str)
	//{
		str = get_next_line(fd);
	//}

	printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
}