/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:15:29 by hyanagim          #+#    #+#             */
/*   Updated: 2022/09/14 16:16:25 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int argc, char **argv)
{
	int	i;

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
	if (ft_strchr(argv[1], '.') != ft_strrchr(argv[1], '.'))
	{
		write(2, "Error\nFile name is invalid\n", 28);
		exit(1);
	}
	i = 0;
	while (*(argv[1] + i) != '.')
		i++;
	if (ft_strcmp(argv[1] + i, ".ber") != 0)
	{
		write(2, "Error\nEnd of file name needs to be '.bar'\n", 43);
		exit(1);
	}
}
