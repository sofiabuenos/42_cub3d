/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:13:39 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/20 15:17:09 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parameters(int ac)
{
	if (ac != 2)
		return (1);
	return (0);
}

int	extension(char **av)
{
	int		i;
	if (av[1])
	{
		i = ft_strlen(av[1]);
		if (i - 5 < 0 || av[1][i - 5] == '/' || !(ft_strnstr((av[1] + (i - 4)), ".cub", 4)))
			return (1);
	}
	return (0);
}

int	parse(int ac, char **av)
{
	if (parameters(ac))
		return (print_err("Check parameters. Should use ./cub3D path_to_map.cub"), 1);
	if (extension(av))
		return (print_err("Check extension. The file should have a name and a .cub extension"), 1);
	return (0);
}
