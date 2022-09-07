/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:20:13 by hyanagim          #+#    #+#             */
/*   Updated: 2022/05/07 11:16:41 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reput(unsigned int nb, int *cch)
{
	if (nb > 9)
		reput(nb / 10, cch);
	*cch += (ft_putchar('0' + nb % 10));
}

int	ft_putuni(unsigned int nb)
{
	int	cch;

	cch = 0;
	reput(nb, &cch);
	return (cch);
}
