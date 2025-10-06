/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/10/06 23:46:19 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*  utils */
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	*ft_calloc(size_t count, size_t size);
/**************functions*************** */
char	*byte_read(int fd, char **buffer);
char	*join_buffer(char *buffer, int fd);
char	*next_line(char *line);
char	*start_line(char *buffer);
char	*get_next_line(int fd);

#endif
