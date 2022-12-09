#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 10
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char	*ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
char *ft_backslash(char *hold);
char *ft_cpy(char *holdline, char *hold);
int ft_strlen(char *hold);
char	*ft_strdup(char *s1);

#endif