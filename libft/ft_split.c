/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:33:42 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 16:08:32 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntarray(char const *str, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*str == c && *str != '\0')
		str++;
	while (*str != '\0')
	{
		if ((*str != c && *(str + 1) == c) || (*str != c && *(str + 1) == '\0'))
			cnt++;
		if (*(str + 1) == '\0')
			break ;
		str++;
	}
	return (cnt);
}

static char	**getmalloc(size_t size)
{
	char	**array;

	array = malloc(sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	array[size] = NULL;
	return (array);
}

static char	*setarray(char const *str, char c, size_t i)
{
	size_t			start;
	static size_t	pos;

	if (i == 0)
		pos = 0;
	while (str[pos] == c && str[pos] != 0)
		pos++;
	start = pos;
	while (str[pos] != c && str[pos] != 0)
		pos++;
	return (ft_substr(str, start, pos - start));
}

char	**releasememory(char **array, size_t i)
{
	while (i--)
		free(array[i]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = cntarray(s, c);
	array = getmalloc(size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = setarray(s, c, i);
		if (array[i] == NULL)
			return (releasememory(array, i));
		i++;
	}
	return (array);
}
