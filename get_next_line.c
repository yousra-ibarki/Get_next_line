#include "get_next_line.h"
#define BUFFER_SIZE 100

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer;
	int			nb;
	int			i;

	nb = 0;
	i = 0;
	//hold = malloc(sizeof(char) * BUFFER_SIZE + 1);
	// if(!hold)
	// 	return (NULL);
	while (nb > 0 && hold[i] != '\n')
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		nb = read(fd, buffer, BUFFER_SIZE);
		hold = ft_substr(buffer, 0, ft_count(buffer));
	}
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
	printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
}