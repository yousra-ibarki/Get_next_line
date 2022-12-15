#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_line(char *hold)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!hold)
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	next_line = malloc(sizeof(char) * (i + 2));
	if (!next_line)
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		next_line[i] = hold[i];
		i++;
	}
	if (hold[i] == '\n')
		next_line[i] = '\n';
	next_line[i] = '\n';
	next_line[i + 1] = '\0';
	return (next_line);
}

char	*ft_nextone(char *hold)
{
	int		i;
	char	*rest;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(hold);
	if (!hold)
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (len - i) + 1);
	if (!rest)
		return (NULL);
	i++;
	while (hold[i])
		rest[j++] = hold[i++];
	rest[j] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer_hold;
	char		*buffer_line;
	int			nbb;

	nbb = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	hold = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!hold)
		return (NULL);
	buffer_hold = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer_hold)
		return (NULL);
	while (!ft_backslash(hold) && nbb != 0)
	{
		//printf("%s\n", hold);
		nbb = read(fd, buffer_hold, BUFFER_SIZE);
		if (nbb < 0)
		{
			free(buffer_hold);
			free(hold);
			return (NULL);
		}
		buffer_hold[nbb] = '\0';
		hold = ft_strjoin(hold, buffer_hold);
		printf("the hold is %s\n", hold);
	}
	
		printf("the second hold is %s\n", hold);
	free(buffer_hold);
	buffer_line = get_line(hold);
	hold = ft_nextone(hold);
	free(hold);
	return (buffer_line);
}
int	main(void)
{
	int	fd;

	fd = 0;
	fd = open("txt", O_RDWR, 777);
	printf("%s", get_next_line(fd));
	close(fd);
}
