/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:08:32 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 14:41:36 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reput(long cast_n, int fd)
{
	if (cast_n > 9)
		reput(cast_n / 10, fd);
	ft_putchar_fd('0' + cast_n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	cast_n;

	cast_n = (long) n;
	if (cast_n < 0)
	{
		ft_putchar_fd('-', fd);
		cast_n *= -1;
	}
	reput(cast_n, fd);
}
