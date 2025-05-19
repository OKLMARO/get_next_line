/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/20 01:11:45 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *jump_after_n(char *s)
{
	int i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		return (&s[i + 1]);
	return (NULL);
}

char *ft_strchr(char *s, int c)
{
	size_t i;
	char *res;

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

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char *ft_join(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *res;

	if (!s1 && !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	res[i] = '\0';
	return (res);
}

char *get_line(int fd)
{
	char	*buffer;
	char	*res;
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
		res = ft_join(res, buffer);
		if (!res)
		{
			free(buffer);
			return (NULL);
		}
		if (line == 0)
			return (res);
	}
	free(buffer);
	return (res);
}


char *get_next_line(int fd)
{
	static char *after_n;
	char 		*line;
	char 		*res;

	if (!after_n)
	{
		after_n = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!after_n)
			return (NULL);
	}
	line = get_line(fd);
	printf("%s", line);
	if (!line && !after_n)
		return (NULL);
	if (!line && after_n[0])
		return (after_n);
	ft_bzero(after_n, BUFFER_SIZE + 1);
	ft_memcpy(after_n, jump_after_n(line), ft_strlen(jump_after_n(line)));
	res = ft_join(after_n, line);
	free(line);
	return (ft_strsup(res, '\n'));
}

int main(void)
{
	int file = open("get_next_line.c", O_RDONLY);
	char *temp;
	while (temp = get_next_line(file))
	{
		//printf("%s", temp);
		free(temp);
	}
	close(file);
	return (0);
}
