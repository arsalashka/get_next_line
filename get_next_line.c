/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <maearly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:32:19 by maearly           #+#    #+#             */
/*   Updated: 2021/01/21 17:52:56 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remainder(char *stat, char **line, int *flag)
{
	char	*remainder;
	char	*ptr;

	remainder = NULL;
	if (stat)
	{
		if ((ptr = ft_strchr(stat, '\n')))
		{
			*ptr = '\0';
			*flag = 1;
			remainder = ft_strdup(++ptr);
		}
	}
	*line = ft_strdup(stat);
	free(stat);
	return (remainder);
}

char	*ft_lets_read(int fd, char *stat)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;
	char	*tmp;

	while ((bytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bytes] = '\0';
		tmp = stat;
		stat = ft_strjoin(stat, buf);
		free(tmp);
		if (ft_strchr(stat, '\n'))
			break ;
	}
	return (stat);
}

int		get_next_line(int fd, char **line)
{
	static char	*stat;
	int			flag;

	flag = 0;
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, stat, 0))
		return (-1);
	if (!stat && !(stat = ft_strdup("")))
		return (-1);
	stat = ft_lets_read(fd, stat);
	stat = ft_remainder(stat, line, &flag);
	return (flag);
}
