#include "get_next_line.h"

char	return_next(void) 
 {
	
 }
char *get_next_line(int fd)
{
	static char	*hold;
	char		*buffer;
	int			nb;
	int			i;

	hold = NULL;
	nb = 1;
	i = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	nb = read(fd , buffer, BUFFER_SIZE);
	hold = ft_substr(buffer, 0, ft_count(buffer));
	return_next(hold, '\n');
	free(buffer);
	return (hold);
}
int	main(void)
{
	int fd = 0;
	char *str;
	fd = open("txt", O_CREAT | O_RDWR, 777);
	//close(fd);
	//open("txt",O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		str = get_next_line(fd);
	}

	printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
}