/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:40:12 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 14:34:44 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	if (lst == NULL)
		return (cnt);
	while (lst != NULL)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
