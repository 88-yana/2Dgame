/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:06:43 by hyanagim          #+#    #+#             */
/*   Updated: 2022/08/21 12:24:25 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converts(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putnb_hex(va_arg(args, unsigned long long), 'p'));
	if (c == 'd' || c == 'i')
		return (ft_putnb(va_arg(args, int)));
	if (c == 'u')
		return (ft_putuni(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putnb_hex(va_arg(args, unsigned int), 'l'));
	if (c == 'X')
		return (ft_putnb_hex(va_arg(args, unsigned int), 'u'));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_vprintf(const char *s, va_list args)
{
	size_t	cch;

	cch = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s != '%')
		{
			cch += ft_putchar(*s);
			s++;
		}
		if (*s == '%')
		{
			s++;
			cch += ft_converts(*s++, args);
		}
	}
	return (cch);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	va_start(args, s);
	ret = ft_vprintf(s, args);
	va_end(args);
	return (ret);
}
