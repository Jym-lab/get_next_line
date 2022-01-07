/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:39:52 by yjoo              #+#    #+#             */
/*   Updated: 2022/01/07 15:23:43 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*read_buffer(int fd, char *buffer);
char	*save_tmp(char	*buffer);
char	*get_line(char *buffer);

#endif
