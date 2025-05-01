/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:19:26 by jquicuma          #+#    #+#             */
/*   Updated: 2025/05/01 09:53:29 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*current;

	if (!lst || !f || !(*del))
		return (NULL);
	begin = ft_lstnew((*f)(lst->content));
	if (!begin)
		return (NULL);
	current = begin;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew((*f)(lst->content));
		if (!current->next)
		{
			ft_lstclear(&begin, (*del));
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (begin);
}
