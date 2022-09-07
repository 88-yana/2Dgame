/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:05:33 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/17 22:27:07 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s_len = ft_strlen(s1);
	start = 0;
	while (start < s_len && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = s_len - 1;
	while (end >= start && ft_strchr(set, s1[end]) != NULL)
		end--;
	if (end >= start)
		return (ft_substr(s1, start, end - start + 1));
	else
		return (ft_strdup(""));
}

//set も　NULL
//strdup でいい