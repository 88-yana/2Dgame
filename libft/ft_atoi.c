/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:30:22 by hyanagim          #+#    #+#             */
/*   Updated: 2022/05/15 17:55:35 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	ans;
	int			sign;

	ans = 0;
	sign = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ - 44;
	while (ft_isdigit(*str))
	{
		if (sign * ans < (LLONG_MIN + (long long)(*str - '0')) / 10)
			return ((int) LLONG_MIN);
		if (sign * ans > (LLONG_MAX - (long long)(*str - '0')) / 10)
			return ((int) LLONG_MAX);
		ans = ans * 10 - (long long)(*str++ - '0');
	}
	return ((int) ans * sign);
}
