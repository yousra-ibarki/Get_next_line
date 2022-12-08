#include "get_next_line.h"

static char	*mystrcpy(char *ss, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

static char	*ft_strcat(char *ss, const char *s)
{
	int	len;
	int	i;

	len = ft_strlen(ss);
	i = 0;
	while (s[i])
	{
		ss[len + i] = s[i];
		i++;
	}
	ss[i + len] = '\0';
	return (ss);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new;

	i = 0;
	if (!s1 || !s2)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	mystrcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}


static char	*mystrcpy(char *ss, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

static char	*ft_strcat(char *ss, const char *s)
{
	int	len;
	int	i;

	len = ft_strlen(ss);
	i = 0;
	while (s[i])
	{
		ss[len + i] = s[i];
		i++;
	}
	ss[i + len] = '\0';
	return (ss);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new;

	i = 0;
	if (!s1 || !s2)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	mystrcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
char *ft_backslash(char *hold)
{
    int i = 0;
    if(hold == NULL)
        return NULL;
    while(hold[i])
    {
        if(hold[i] == '\n')
            return hold + i;
        i++;
    }
    return 0;
}
char *ft_cpy(char *holdline, char *hold)
{
    int i = 0;
    while(hold[i] && hold[i] != '\n')
    {
        holdline[i] = hold[i];
        i++;
    }
    holdline[i] = '\0';
    return holdline;
}
int ft_strlen(char *hold)
{
    int i = 0;
    while(hold[i])
        i++;
    return i;
    
}