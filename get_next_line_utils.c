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

char		*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s != (char)c)
		return (NULL);
	return ((char *)s);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (NULL == buf)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(s1))
	{
		buf[i] = s1[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char		*ft_strnew(size_t i)
{
	char	*str;
	size_t	k;

	k = 0;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	while (k < i)
	{
		str[k] = '0';
		i--;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*buf;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char*)malloc(sizeof(char) * len);
	if ((!s1 && !s2) || !join)
		return (NULL);
	buf = join;
	while (*s1)
		*(buf++) = *(s1++);
	while (*s2)
		*(buf++) = *(s2++);
	*buf = '\0';
	return (join);
}
