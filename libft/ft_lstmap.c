/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:40:03 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/16 14:47:09 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	newlist = ft_lstnew(lst->content);
	if (newlist == NULL)
		return (NULL);
	newlist->content = f(newlist->content);
	lst = lst->next;
	while (lst != NULL)
	{
		node = ft_lstnew(lst->content);
		if (node == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		node->content = f(node->content);
		ft_lstadd_back(&newlist, node);
		lst = lst->next;
	}
	return (newlist);
}
