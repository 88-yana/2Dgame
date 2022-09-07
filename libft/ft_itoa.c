/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:34:29 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 14:25:38 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntdigit(long cast_n)
{
	int	digit;

	digit = 1;
	while (cast_n > 9)
	{
		cast_n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long	cast_n;
	int		digit;
	char	*s;

	digit = 0;
	cast_n = (long) n;
	if (cast_n < 0)
	{
		digit++;
		cast_n *= -1;
	}
	digit += cntdigit(cast_n);
	s = malloc(digit + 1);
	if (s == NULL)
		return (NULL);
	s[digit] = '\0';
	while (digit--)
	{
		s[digit] = (cast_n % 10) + '0';
		cast_n /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
