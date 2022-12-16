/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:45 by yoibarki          #+#    #+#             */
/*   Updated: 2022/12/16 16:11:47 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

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
	i++;
	rest = malloc(sizeof(char) * (len - i) + 1);
	if (!rest)
		return (NULL);
	while (hold[i])
		rest[j++] = hold[i++];
	rest[j] = '\0';
	free(hold);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*hold[4096];
	char		*buffer_hold;
	int			nbb;
	char		*ret;

	nbb = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer_hold = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer_hold)
		return (NULL);
	while (!ft_backslash(hold[fd]) && nbb != 0)
	{
		nbb = read(fd, buffer_hold, BUFFER_SIZE);
		if (nbb < 0)
		{
			free(buffer_hold);
			if (hold[fd])
				free(hold[fd]);
			return (NULL);
		}
		else if (nbb == 0)
		{
			free(buffer_hold);
			ret = ft_strdup(hold[fd]);
			if (hold[fd])
			{
				free(hold[fd]);
				hold[fd] = NULL;
			}
			if (ret[0] == '\0')
			{
				free(ret);
				return (NULL);
			}
			return (ret);
		}
		buffer_hold[nbb] = '\0';
		if (hold[fd])
			hold[fd] = ft_strjoin(hold[fd], buffer_hold);
		else
			hold[fd] = ft_strdup(buffer_hold);
	}
	free(buffer_hold);
	buffer_hold = get_line(hold[fd]);
	hold[fd] = ft_nextone(hold[fd]);
	return (buffer_hold);
}
// int	main(void)
// {
// 	int	fd;

// 	fd = 0;
// 	fd = open("txt", O_RDWR, 777);
// 	char *str = get_next_line(fd);
// 	printf("%s",str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s",str);

// }
