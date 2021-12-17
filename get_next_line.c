/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:39:50 by yjoo              #+#    #+#             */
/*   Updated: 2021/12/17 16:47:11 by yjoo             ###   ########.fr       */
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
	//개행이면 개행을 집어넣어주고, eof라면 그냥 마지막에 널포인터를 넣어준다.
	if (tmp[i] == '\n')
	{
		line[i] = tmp[i];
		i++;//널포인터를 넣어줘야 하므로 값을 증가
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
	//먼저 line에 들어간 문자를 제거함
	while (tmp[i] && tmp[i] != '\n')
		i++;
	//현재 위치는 NL
	//NL까지의 길이를 제외한 나머지 길이와 + 널포인터의 길이만큼 할당
	remstr = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!remstr)
		return (NULL);
	i++;//NL길이 뒤부터 붙여야 하므로 i값 증가
	while (tmp[i])
		remstr[j++] = tmp[i++];
	//쭉 복사해서 붙여주고 마지막에 널 포인터
	remstr[j] = 0;
	//tmp는 더이상 필요없으므로 메모리 해제
	free(tmp);
	return (remstr); 
}
char	*read_line(int fd, char *tmp)
{
	int		read_len;
	char	*buf;

	read_len = 1;
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
		tmp = ft_strjoin(tmp, buf);
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
	line = get_line(tmp);
	tmp = save_tmp(tmp);
	return (line);
}
