#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 10

char *get_next_line(int fd);
char *ft_backslash(char *hold);
char *ft_cpy(char *holdline, char *hold);
int ft_strlen(char *hold);
char	*ft_strjoin(char const *s1, char const *s2);



#endif