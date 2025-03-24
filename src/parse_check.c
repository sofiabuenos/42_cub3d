/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:34:34 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/24 17:38:56 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_filename(t_game *cub, char **av)
{
	int		i;

	if (av[1])
	{
		i = ft_strlen(av[1]);
		if (i - 5 < 0 || av[1][i - 5] == '/' || \
			!(ft_strnstr((av[1] + (i - 4)), ".cub", 4)))
			quit(cub, ER_FILE);
	}
	cub->file_name = ft_strdup(av[1]);
}

void	check_empty_file(t_game *cub)
{
	if (!cub->file[0] || check_is_empty(cub->file))
		quit(cub, ER_EMPTY);
}

void	check_param(t_game *cub, int ac, char **av)
{
	if (ac != 2)
		quit(cub, ER_PARAM);
	if (av[1][0] == '\0')
		quit(cub, ER_FILE);
}

void	check_duplicate(t_game *cub, char *element, char *texture, char *str)
{
	if (texture)
	{
		free(str);
		if (!ft_strncmp(element, NO, 3))
			quit(cub, "Duplicate NO texture");
		else if (!ft_strncmp(element, SO, 3))
			quit(cub, "Duplicate SO texture");
		else if (!ft_strncmp(element, WE, 3))
			quit(cub, "Duplicate WE texture");
		else if (!ft_strncmp(element, EA, 3))
			quit(cub, "Duplicate EA texture");
		else if (!ft_strncmp(element, F, 2))
			quit(cub, "Duplicate F color");
		else if (!ft_strncmp(element, C, 2))
			quit(cub, "Duplicate C color");
	}
}
