/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:32:04 by hyanagim          #+#    #+#             */
/*   Updated: 2022/04/11 15:37:33 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst != src)
		while (n--)
			((unsigned char *)dst)[n] = ((const unsigned char *)src)[n];
	return (dst);
}

// to cause a segmentation fault, delete the statement
// if (dst == src)
// 	return (dst);
// depends on n
// However, the error does not happen every time
// not need to consider it

// does not need to cast void *dst to unsigned char * when returning it.

//	void *memcpy(void *dest, const void *src, size_t n);
//	
//	DESCRIPTION
//	The memcpy() function copies n bytes
//	from memory area src to memory area dest.
//	The memory areas must not overlap.
//	RETURN VALUE
//	The memcpy() function returns a pointer to dest.