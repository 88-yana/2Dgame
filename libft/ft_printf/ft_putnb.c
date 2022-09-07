/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:18:31 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 16:57:45 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reput(long cast_nb, int *cch)
{
	if (cast_nb > 9)
		reput(cast_nb / 10, cch);
	*cch += (ft_putchar('0' + cast_nb % 10));
}

int	ft_putnb(int nb)
{
	int		cch;
	long	cast_nb;

	cast_nb = (long) nb;
	cch = 0;
	if (cast_nb < 0)
	{
		cch += ft_putchar('-');
		cast_nb *= -1;
	}
	reput(cast_nb, &cch);
	return (cch);
}
