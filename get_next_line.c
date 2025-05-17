/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/17 15:15:06 by oamairi          ###   ########.fr       */
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
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && lecture > 0)
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		buffer[lecture] = '\0';
		str = ft_join(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	if (lecture <= 0)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*s1;
	char		*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!s1)
			return (NULL);
		s1 = ft_strsup(jump_after_n(line), '\0');
	}
	else
		str = ft_join(s1, line);
	printf("str : %s\n", str);
	s1 = ft_strsup(jump_after_n(line), '\0');\
	printf("s1 : %s\n", s1);
	free(line);
	if (line == NULL)
	{
		free(s1);
		return (NULL);
	}
	//printf("s1 : %s\nline : %s\n", s1, line);
	return (ft_strsup(ft_join(s1, line), '\n'));
}

int	main(void)
{
	int file = open("test.txt", O_RDONLY);
	char*	temp;
	while (temp = get_next_line(file))
	{
		printf("gnl : %s", temp);
		free(temp);  
	}
	close(file);
	return (0);
}
