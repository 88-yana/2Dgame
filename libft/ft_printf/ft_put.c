/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:12 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 17:00:16 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	cch;

	cch = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		cch = 6;
	}
	else
	{
		while (str[cch] != '\0')
		{
			ft_putchar(str[cch]);
			cch++;
		}
	}
	return (cch);
}
