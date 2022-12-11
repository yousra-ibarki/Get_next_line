/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:24:12 by yoibarki          #+#    #+#             */
/*   Updated: 2022/12/11 08:24:14 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_backslash(char *hold)
{
	int	i;

	i = 0;
	return (NULL);
	while (hold[i])
	{
		if (hold[i] == '\n')
			return (hold + i);
		i++;
	}
	return (0);
}

static char	*mystrcpy(char *ss, const char *s)
{
	int	i;

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

char	*strrcpy(const char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*arr;

	len = ft_strlen(s1);
	arr = malloc(len * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);
	arr = strrcpy(s1, arr);
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new;

	i = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
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

char	*ft_cpy(char *holdline, char *hold)
{
	int	i;

	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		holdline[i] = hold[i];
		i++;
	}
	holdline[i] = '\n';
	i += 1;
	holdline[i] = '\0';
	return (holdline);
}

int	ft_strlen(char *hold)
{
	int i = 0;
	while (hold[i])
		i++;
	return (i);
}

