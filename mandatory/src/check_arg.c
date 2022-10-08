/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:15:29 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/08 11:21:32 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_arg(int argc, char **argv)
{
	char	*ptr;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nneed file name", 2);
		exit(1);
	}
	if (ft_strcmp(argv[1], ".ber") == 0)
	{
		ft_putendl_fd("Error\nFile name is invalid", 2);
		exit(1);
	}
	ptr = ft_strrchr(argv[1], '.');
	if (ft_strcmp(ptr, ".ber") != 0)
	{
		ft_putendl_fd("Error\nEnd of file name needs to be '.bar'", 2);
		exit(1);
	}
}
