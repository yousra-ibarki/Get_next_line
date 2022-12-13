/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:24:46 by yoibarki          #+#    #+#             */
/*   Updated: 2022/12/11 08:24:47 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_backslash(char *hold, int nbb);
char	*ft_cpy(char *holdline, char *hold);
char	*ft_strdup(char *s1);
int		ft_strlen(char *hold);

#endif
