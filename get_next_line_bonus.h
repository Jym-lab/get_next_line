/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:39:52 by yjoo              #+#    #+#             */
/*   Updated: 2022/01/19 16:23:51 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define OPEN_MAX 256

typedef struct s_list
{
	int				fd;
	char			*buffer;
	struct s_list	*next;
}	t_list;

void	free_node(t_list **h_node, t_list *cur_node);

t_list	*find_node(t_list **h_node, int fd);
t_list	*new_node(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*read_buffer(int fd, char *buffer);
char	*save_tmp(char	*buffer);
char	*get_line(char *buffer);

#endif
