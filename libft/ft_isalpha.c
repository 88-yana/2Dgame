/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:16:41 by hyanagim          #+#    #+#             */
/*   Updated: 2022/05/15 17:55:12 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) + ft_islower(c));
}

// ascii
// 101   65    41    A
// 132   90    5A    Z
// 141   97    61    a
// 172   122   7A    z

//int isalpha(int c);

//	isalpha()
//	checks for an alphabetic character;
//	in the standard "C" locale, it is equivalent to (isupper(c) || islower(c)).
//	In some locales, there may be additional  characters
//	for which isalpha() is true—letters
//	which are neither uppercase nor lowercase.

//	int islower(int c);
//	int isupper(int c);

//	isupper()
//	checks for an uppercase letter.
//	islower()
//	checks for a lowercase character.

// RETURN VALUE
//	The values returned are
//	nonzero if the character c falls into the tested class,
//	and zero if not.