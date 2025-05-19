/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:07:52 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/20 00:22:15 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_sup(const char *s1, int c)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	return (i);
}

char	*ft_strsup(char *s, int c)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * ft_strlen_sup((char *) s, c) + 1);
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i <= ft_strlen_sup(s, c))
	{
		dest[i] = s[i];
		i++;
	}
	free(s);
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!dest)
		return (0);
	while (src[i] && i <= BUFFER_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	while (i < n)
	{
		c = (unsigned char *)s;
		c[i] = '\0';
		i++;
	}
}

void	ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*dest_c;
	char	*src_c;

	if (!dest && !src)
		return ;
	dest_c = (char *) dest;
	src_c = (char *) src;
	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
}
