/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:15:29 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/21 11:31:45 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_arg(int argc, char **argv)
{
	char	*ptr;

	if (argc != 2)
	{
		write(2, "Error\nneed file name\n", 22);
		exit(1);
	}
	if (ft_strcmp(argv[1], ".ber") == 0)
	{
		write(2, "Error\nFile name is invalid\n", 28);
		exit(1);
	}
	ptr = ft_strrchr(argv[1], '.');
	if (ft_strcmp(ptr, ".ber") != 0)
	{
		write(2, "Error\nEnd of file name needs to be '.bar'\n", 43);
		exit(1);
	}
}
