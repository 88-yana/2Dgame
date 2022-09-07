/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:23:47 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 14:35:50 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*trans_s;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	trans_s = malloc(len + 1);
	if (trans_s == NULL)
		return (NULL);
	trans_s[len] = '\0';
	while (len--)
		trans_s[len] = f(len, s[len]);
	return (trans_s);
}
