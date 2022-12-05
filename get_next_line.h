#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char	*strrcpy(char *src, char *dst);
char		*ft_strdup(char *s1);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_count(char *str);
char		*get_next_line(int fd);

#endif