/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:30:31 by hyanagim          #+#    #+#             */
/*   Updated: 2022/05/15 18:02:12 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char) c)
			return ((char *)(s));
		if (*s == 0)
			break ;
		s++;
	}
	return (NULL);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	s_len;
// 	size_t	i;

// 	s_len = ft_strlen(s);
// 	i = 0;
// 	while (i < s_len + 1)
// 	{
// 		if (s[i] == (char) c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	return (NULL);
// }