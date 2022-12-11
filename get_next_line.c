/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:24:24 by yoibarki          #+#    #+#             */
/*   Updated: 2022/12/11 08:24:34 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *hold)
{
	int		i;
	char	*holdline;

	i = 0;
	if (!hold)
		return (0);
	while (hold[i] && hold[i] != '\n')
		i++;
	holdline = malloc(sizeof(char) * (i + 2));
	if (!holdline)
		return (NULL);
	holdline = ft_cpy(holdline, hold);
	return (holdline);
}

char	*ft_nextone(char *hold)
{
	int		i;
	int		k;
	int		len;
	char	*nextone;

	i = 0;
	k = 0;
	len = ft_strlen(hold);
	if (!hold)
		return (0);
	while (hold[i] && hold[i] != '\n')
		i++;
	nextone = malloc(sizeof(char) * (len - i) + 1);
	if (!nextone)
		return (0);
	i++;
	while (hold[i])
	{
		nextone[k] = hold[i];
		k++;
		i++;
	}
	nextone[k] = '\0';
	free(hold);
	return (nextone);
}

char	*ft_read(char *hold, int fd, char *buffer)
{
	int	nbb;

	nbb = 1;
	while (!ft_backslash(hold) && nbb != 0)
	{
		printf("%s\n%d", hold, nbb);
		nbb = read(fd, buffer, BUFFER_SIZE);
		if (nbb <= 0)
		{
			free(buffer);
			return (0);
		}
		buffer[nbb] = '\0';
		hold = ft_strjoin(hold, buffer);
	}
	//free(buffer);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	hold = ft_read(hold, fd, buffer);
	if (!hold)
		return (NULL);
	free(buffer);
	buffer = ft_getline(hold);
	hold = ft_nextone(hold);
	free(hold);
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = 0;
	fd = open("txt", O_CREAT | O_RDWR, 777);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	// str = get_next_line(fd);
	// printf("%s", str);

	// //  printf("%s", get_next_line(fd));
	// //  printf("%s", get_next_line(fd));
	// // printf("%s", get_next_line(fd));
		//free(str);
	close(fd);
// 	while (1)
// 		;
 }
