/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:47:15 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/19 11:59:18 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlen_sup(const char *s1, int c);
char	*ft_strsup(char *s, int c);
char	*ft_strdup(char *src);
void	ft_bzero(void *s, size_t n);

#endif
