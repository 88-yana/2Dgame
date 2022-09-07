/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:32:19 by hyanagim          #+#    #+#             */
/*   Updated: 2022/04/16 20:04:29 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != 0)
		cnt++;
	return (cnt);
}

//include stddef.h to use size_t

//man strlen
// size_t strlen(const char *s);
// DESCRIPTION
// The strlen() function calculates the length of the string pointed to by s,
// excluding the terminating null byte ('\0').
// RETURN VALUE
// The strlen() function returns the number of characters
// in the string pointed to by s.

// != 0, because '\0' = 0
// minus characters are possible