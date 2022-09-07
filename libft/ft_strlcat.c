/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:32:13 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 14:39:22 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while ((0 < dstsize && dst_len + i < dstsize - 1) && i < src_len)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[dst_len + i] = '\0';
	if (dst_len > dstsize)
		return (src_len + dstsize);
	return (dst_len + src_len);
}
