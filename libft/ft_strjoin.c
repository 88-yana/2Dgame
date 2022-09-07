/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:38:34 by hyanagim          #+#    #+#             */
/*   Updated: 2022/08/22 06:57:41 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*line;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	line = malloc(s1_len + s2_len + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, s1, s1_len + s2_len + 1);
	ft_strlcat(line, s2, s1_len + s2_len + 1);
	line[s1_len + s2_len] = '\0';
	return (line);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	char	*line;
// 	size_t	i;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	line = malloc(s1_len + s2_len + 1);
// 	if (line == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < s1_len)
// 	{
// 		line[i] = s1[i];
// 		i++;
// 	}
// 	while (i < s1_len + s2_len)
// 	{
// 		line[i] = s2[i - s1_len];
// 		i++;
// 	}
// 	line[s1_len + s2_len] = 0;
// 	return (line);
// }