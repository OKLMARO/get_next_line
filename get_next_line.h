/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:47:15 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/11 00:35:56 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			c;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*get_str_of_tlist(t_list **lst);

#endif
