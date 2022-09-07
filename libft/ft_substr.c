/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:03:01 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 14:38:15 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len > start && s_len - start > len)
		sub = malloc(len + 1);
	else if (s_len > start)
		sub = malloc(s_len - start + 1);
	else
		sub = malloc(1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (len > i && s_len > start + i)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
