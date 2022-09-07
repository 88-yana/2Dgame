/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:57:34 by hyanagim          #+#    #+#             */
/*   Updated: 2022/05/11 21:16:28 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putnb_hex(unsigned long long nbr, char flag);
int		ft_putnb(int nb);
int		ft_putuni(unsigned int nb);
int		ft_printf(const char *s, ...);

#endif