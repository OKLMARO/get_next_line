/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/18 12:55:11 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*jump_after_n(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n' && s[i + 1] != 0)
		return (ft_strdup(&s[i + 1]));
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	if (!s)
		return (0);
	res = (char *) s;
	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == (unsigned char) c)
			return (&res[i]);
		i++;
	}
	if (res[i] == (unsigned char) c)
		return (&res[i]);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

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
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}

char	*get_line(int fd)
{
	char	*buffer;
	char	*str;
	ssize_t		lecture;

	str = NULL;
	lecture = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n') && lecture > 0)
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		//printf("buffer : %s\n", buffer);
		str = ft_join(str, buffer);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		//printf("str : %s\n", str);
	}
	free(buffer);
	//printf("str : %s | lecture %i\n", str, lecture);
	if (ft_strlen(str))
		return (str);
	//if (lecture <= 0)
	return (NULL);
	//return (str);
}

char	*get_next_line(int fd)
{
	static char	*after_n;
	char		*line;
	char		*res;
	
	if (!after_n)
	{
		after_n = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!after_n)
			return (NULL);
		ft_bzero(after_n, BUFFER_SIZE);
	}
	line = get_line(fd);
	if (line == NULL && !after_n[0])
	{
		free(after_n);
		return (NULL);
	}
	if (line == NULL && after_n[0])
		return (after_n);
	res = ft_join(after_n, line);
	after_n = jump_after_n(line);
	free(line);
	return (ft_strsup(res, '\n'));
}

int	main(void)
{
	int file = open("test.txt", O_RDONLY);
	char*	temp;
	while (temp = get_next_line(file))
	{
		printf("%s", temp);
		free(temp);  
	}
	close(file);
	return (0);
}
