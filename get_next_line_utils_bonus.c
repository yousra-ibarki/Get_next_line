#include "get_next_line_bonus.h"
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*arr;
	if(!s1)
	{
		arr = malloc(1);
		arr[0] = '\0';
		return(arr);
	}
	len = ft_strlen(s1);
	arr = malloc(len * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);
	arr = ft_strcpy(arr, s1);
	return (arr);
}

char	*ft_backslash(char *hold)
{
	int	i;

	i = 0;
	if (!hold)
		return (NULL);
	while (hold[i])
	{
		if (hold[i] == '\n') //&& nbb <= BUFFER_SIZE
			return (hold + i);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sr;
	int		i;

	i = 0;
	dest = (char *)dst;
	sr = (char *)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		dest[i] = sr[i];
		i++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*ptr;

	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, len1);
	ft_memcpy(ptr + len1, s2, len2);
	ptr[len1 + len2] = '\0';
	free(s1);
	return (ptr);
}
