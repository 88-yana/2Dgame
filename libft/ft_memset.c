/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:32:10 by hyanagim          #+#    #+#             */
/*   Updated: 2022/04/10 18:33:12 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t n)
{
	while (n--)
		((unsigned char *)buf)[n] = (unsigned char) c;
	return (buf);
}

//	void *memset(void *s, int c, size_t n);

//DESCRIPTION
//	The memset() function fills the first n bytes of the memory area
//	pointed to by s with the constant byte c.

//RETURN VALUE
//	The memset() function returns a pointer to the memory area s.
