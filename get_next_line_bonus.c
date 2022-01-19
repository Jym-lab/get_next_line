/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:39:50 by yjoo              #+#    #+#             */
/*   Updated: 2022/01/19 16:25:47 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		tmp[j++] = buffer[i++];
	tmp[j] = 0;
	free(buffer);
	return (tmp);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	int		read_len;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	read_len = 1;
	while (read_len > 0 && !ft_strchr(buffer, '\n'))
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_len] = 0;
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

t_list	*find_node(t_list **h_node, int fd)
{
	t_list	*node;

	if (!(*h_node))
	{
		*h_node = new_node(fd);
		return (*h_node);
	}
	node = *h_node;
	while (node)
	{
		if (node->fd == fd)
			break ;
		if (node->next == NULL)
		{
			node->next = new_node(fd);
			if (!node)
				return (NULL);
		}
		node = node->next;
	}
	return (node);
}

char	*get_next_line(int fd)
{
	static t_list	*h_node = 0;
	t_list			*cur_node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	cur_node = find_node(&h_node, fd);
	cur_node->buffer = read_buffer(cur_node->fd, cur_node->buffer);
	if (cur_node->buffer == NULL)
	{
		free_node(&h_node, cur_node);
		return (NULL);
	}
	line = get_line(cur_node->buffer);
	cur_node->buffer = save_buffer(cur_node->buffer);
	if (cur_node->buffer == NULL)
		free_node(&h_node, cur_node);
	return (line);
}
