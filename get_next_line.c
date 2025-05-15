/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/15 12:46:29 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*jump_after_n(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n' && s[i + 1] != 0)
		return (&s[i + 1]);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

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
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	int			lecture;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = 0;
		str = ft_join(str, jump_after_n(buffer));
		free(buffer);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	lecture = 1;
	while (!ft_strchr(buffer, '\n') && lecture > 0)
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (lecture != BUFFER_SIZE)
			buffer[lecture] = '\0';
		str = ft_join(str, buffer);
		if (!str)
			return (NULL);
	}
	if (lecture == 0)
	{
		free(buffer);
		return (ft_strsup(str, '\0'));
	}
	return (ft_strsup(str, '\n'));
}

int	main(void)
{
	int file = open("test.txt", O_RDONLY);
	char *temp = get_next_line(file);
	printf("%s\n", temp);
	free(temp);
	temp = get_next_line(file);
	printf("%s\n", temp);
	free(temp);
	temp = get_next_line(file);
	printf("%s\n", temp);
	close(file);
	//free(temp);
	return (0);
}
