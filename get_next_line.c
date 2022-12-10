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
	while(hold[i] && hold[i] != '\n')
		i++;
	nextone = malloc(sizeof(char) * (len - i) + 1);
	if(!nextone)
	return 0;
	i++;
	while(hold[i])
	{
		nextone[k] = hold[i];
		k++;
		i++;
	}
	nextone[k] = '\0';
	free(hold);
	return nextone;
	
}

char *get_next_line(int fd)
{
	static char *hold;
	char *buffer;
	char *holdline; 
	int nbb = 1;
	int i = 0;
	if(fd < 0 || BUFFER_SIZE < 1)
		return 0;
			// hold = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return NULL;
	while(!ft_backslash(hold) && nbb != 0)
	{
		nbb = read(fd, buffer, BUFFER_SIZE);
		if(nbb < 0)
		{
			free(buffer);
			return 0;
		}
		buffer[nbb] = '\0';
		hold = ft_strjoin(hold, buffer);

	}
	buffer = hold;
	if(!hold)
	{
		if(buffer)
			free(buffer);
		hold = NULL;
			return NULL;
	}
	hold = buffer;
	if(hold)
		holdline = ft_getline(hold);
		//printf("%c\n", holdline[0]);
	hold = ft_nextone(hold);
	// printf("%s", hold);
	return holdline;
}

// char *nd_get_line(int fd)
// {
// 	char str;
// 	int i;
// }

int main()
{
	int fd = 0;
	fd = open("txt", O_CREAT | O_RDWR, 777);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}