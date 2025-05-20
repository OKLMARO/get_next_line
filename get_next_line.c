/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/20 14:55:16 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (free(s1), (res));
}

char	*get_line(int fd)
{
	char	*buffer;
	char	*res;
	char	*temp;
	int		line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	res = NULL;
	line = 1;
	while (!ft_strchr(res, '\n') && line > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		line = read(fd, buffer, BUFFER_SIZE);
		res = ft_strjoin(res, buffer);
		if (!temp)
			return (free(buffer), free(res), (NULL));
	}
	free(buffer);
	if (line <= 0)
		return (free(res), (NULL));
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*after_n;
	char		*line;
	char		*res;

	
}

int	main(void)
{
	int file = open("test.txt", O_RDONLY);
	char *temp;
	while (temp = get_next_line(file))
	{
		printf("%s", temp);
	}
	close(file);
	return (0);
}
