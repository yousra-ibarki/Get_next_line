#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_backslash(char *hold);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *hold);
char	*ft_nextone(char *hold);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);

#endif