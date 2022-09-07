/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:30:37 by hyanagim          #+#    #+#             */
/*   Updated: 2022/04/23 19:22:49 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t s_len)
{
	size_t	f_len;

	if (*find == 0)
		return ((char *) s);
	f_len = ft_strlen(find);
	while (s_len && *s != 0)
	{
		if (s_len < f_len)
			return (NULL);
		if (ft_strncmp(s, find, f_len) == 0)
			return ((char *) s);
		s++;
		s_len--;
	}
	return (NULL);
}
