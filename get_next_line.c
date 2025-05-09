/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/09 12:04:54 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*str;
	int			i;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, res, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (res[i])
		{
			if (res[i] == '\n')
			{
				str = ft_strjoin(str, res);
				if (!str)
					return (NULL);
				return (str);
			}
			i++;
		}
	}
	str = ft_strjoin(str, res);
	if (!str)
		return (NULL);
	return (str);
}

int	main(void)
{
	int file = open("test.txt", O_RDONLY);
	char *temp = get_next_line(file);
	close(file);
	printf("%s", temp);
	return (0);
}
