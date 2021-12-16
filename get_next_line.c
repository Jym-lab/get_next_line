/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:39:50 by yjoo              #+#    #+#             */
/*   Updated: 2021/12/16 17:39:30 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buf)
{
	int		i;
	char	*tmp;
	
	if (!buf[0])
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != "\n")
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1)
	if (!tmp)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != "\n")
	{
		tmp[i] = buf[i];
		i++;
	}
	if (buf[i] == "\n")
	{
		tmp[i] = buf[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*get_buf(char *buf)
{
	
}

char	*get_next_line(int fd)
{
	int	byte;
	char	*line;
	char	*tmp;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	byte = 1;
	while (byte != 0 && !ft_strchr(buf, "\n"))
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte] = 0;
		buf = ft_strjoin(buf, tmp);
	}
	free(tmp);
	line = get_line(buf);
	buf = // 출력 후 남는 문자열을 임시저장한다.
	return (line);
}