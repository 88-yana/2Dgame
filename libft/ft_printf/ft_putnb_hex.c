/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:44:28 by hyanagim          #+#    #+#             */
/*   Updated: 2022/06/18 16:59:06 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reputbase(unsigned long long nbr, char *base, int *cch)
{
	unsigned long long	base_size;

	base_size = 16;
	if (nbr >= base_size)
		reputbase(nbr / base_size, base, cch);
	*cch += (ft_putchar(base[nbr % base_size]));
}

int	ft_putnb_hex(unsigned long long nbr, char flag)
{
	int	cch;

	cch = 0;
	if (flag == 'p')
	{
		write(1, "0x", 2);
		cch += 2;
	}
	if (flag == 'l' || flag == 'p')
		reputbase(nbr, "0123456789abcdef", &cch);
	else if (flag == 'u')
		reputbase(nbr, "0123456789ABCDEF", &cch);
	return (cch);
}
