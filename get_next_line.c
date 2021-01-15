/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:32:19 by maearly           #+#    #+#             */
/*   Updated: 2021/01/15 13:32:28 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_strcpy(char *dest, const char *source)
{
	int i;

	i = 0;
	while (1)
	{
		dest[i] = source[i];
		if (dest[i] == '\0')
		{
			break ;
		}
		i++;
	}
}

char		*check_remainder(char *remainder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (remainder)
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			remainder = ft_strnew(1);
		}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int			get_next_line(int fd, char **line)
{
	static char		*remainder;
	char			buf[BUFF_SIZE + 1];
	int				byte_was_read;
	char			*p_n;
	char			*tmp;

	p_n = check_remainder(remainder, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFF_SIZE)))
	{
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		buf[byte_was_read] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (0);
}

int			main(void)
{
	int		fd;
	char	*line;

	line = "hello world";
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	return (0);
}
