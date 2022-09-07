/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:39:45 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 14:17:46 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*suc;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		suc = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = suc;
	}
	lst = NULL;
}
