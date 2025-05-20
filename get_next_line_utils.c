/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:07:52 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/20 20:58:45 by oamairi          ###   ########.fr       */
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
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	for (size_t j = 0; j < i; j++)
		dest[j] = s[j];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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

size_t	ft_strlen(const char *str)
{
	size_t	i;
	

	if(!str)
		return 0;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
