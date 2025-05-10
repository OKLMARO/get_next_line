/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/11 00:35:12 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str_of_tlist(t_list **lst)
{
	char	*str;
	int		i;
	t_list	*list_char;

	str = malloc(sizeof(char) * (ft_lstsize(*lst) + 1));
	if (!str)
		return (NULL);
	i = 0;
	list_char = *lst;
	while (list_char)
	{
		str[i] = list_char->c;
		i++;
		list_char = list_char->next;
	}
	str[i] = '\0';
	return (str);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list	*ft_lstnew(char c)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->c = c;
	new->next = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	char			*res;
	static t_list	**str;
	int				i;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = malloc(sizeof(char) * BUFFER_SIZE);
	if (!res)
		return (NULL);
	str = malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	while (read(fd, res, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (res[i])
		{
			if (res[i] == '\n')
				return (get_str_of_tlist(str));
			ft_lstadd_back(str, ft_lstnew(res[i]));
			i++;
		}
	}
	return (get_str_of_tlist(str));
}

/*int	main(void)
{
	int file = open("test.txt", O_RDONLY);
	char *temp = get_next_line(file);
	printf("%s\n", temp);
	temp = get_next_line(file);
	printf("%s\n", temp);
	temp = get_next_line(file);
	printf("%s\n", temp);
	close(file);
	free(temp);
	return (0);
}*/
