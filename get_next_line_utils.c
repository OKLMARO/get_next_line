/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:07:52 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/11 10:22:09 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	temp = lst;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	ft_lstfree(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*lst_next;

	if (!lst)
		return ;
	lst_next = *lst;
	while (lst_next)
	{
		lst_next = lst_next->next;
		ft_lstfree(*lst);
		*lst = lst_next;
	}
}
