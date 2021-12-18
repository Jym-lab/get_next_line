/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:39:50 by yjoo              #+#    #+#             */
/*   Updated: 2021/12/18 19:01:49 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*save_tmp(char	*tmp)
{
	int		i;
	int		j;
	char	*remstr;
	
	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	remstr = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!remstr)
		return (NULL);
	i++;
	while (tmp[i])
		remstr[j++] = tmp[i++];
	remstr[j] = 0;
	free(tmp);
	return (remstr); 
}

char	*read_line(int fd, char *tmp)
{
	int		read_len;
	size_t	tmp_len;
	char	*buf;

	read_len = 1;
	tmp_len = ft_strlen(tmp);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read_len != 0 && !chrnl(buf))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_len] = 0;
		tmp = ft_strjoin(tmp, buf);
		if (tmp_len == ft_strlen(tmp))
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	tmp = read_line(fd, tmp);
	if (!tmp)
		return (NULL);
	line = get_line(tmp);
	tmp = save_tmp(tmp);
	return (line);
}
