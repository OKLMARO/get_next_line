/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/08 02:41:27 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_split(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

int	str_len_split(const char *str, int i, char c)
{
	int	taille;

	taille = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		taille++;
	}
	return (taille);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*str;
	int			i;
	
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (read(fd, res, BUFFER_SIZE) > 0)
	{
		while (res[i])
		{
			if (res[i] == '\n')
			{
				str = malloc(sizeof(char) * (str_len_split(res, 0, '\n') + 1));
				if (!str)
					return (NULL);
				str = ft_strcpy_split(str, res, '\n');
			}
			i++;
		}
	}
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
