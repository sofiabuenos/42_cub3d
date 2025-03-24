/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:55:37 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/24 18:00:56 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_position(t_game *cub, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NSEW", cub->map[y][x]))
			{
				cub->player->pov = map[y][x];
				cub->player->pos.x = x;
				cub->player->pos.y = y;
				map[y][x] = '0';
				return ;
			}
		}
	}
	if (cub->player->pov == 0)
		quit(cub, "Invalid map. Player is not set");
}

bool	check_is_empty(char *row)
{
	while (*row == ' ' || *row == '\n')
		row++;
	if (*row == '\0')
		return (true);
	return (false);
}

void	check_map(t_game *cub, int y)
{
	int			x;
	static int	count_player;

	x = -1;
	while (cub->map[y][++x])
	{
		if (!ft_strchr("01NSEW \n", cub->map[y][x]))
			quit(cub, "Invalid map. There is an invalid character");
		if (ft_strchr("0NSEW", cub->map[y][x]))
		{
			if (ft_strchr("NSEW", cub->map[y][x]))
				count_player++;
			if (count_player > 1)
				quit(cub, "Invalid map. There is more than 1 player");
			if (x == 0 || y == 0 || !cub->map[y + 1]
				|| (size_t)x >= ft_strlen(cub->map[y + 1])
				|| (size_t)x >= ft_strlen(cub->map[y - 1])
				|| cub->map[y][x + 1] == '\n' || cub->map[y][x + 1] == '\0'
				|| cub->map[y][x + 1] == ' ' || cub->map[y][x - 1] == ' '
				|| cub->map[y + 1][x] == ' ' || cub->map[y - 1][x] == ' ')
				quit(cub, "Invalid Map. It is not closed/surrounded by walls");
		}
	}
}

void	parse_map(t_game *cub)
{
	int	y;

	if (!cub->map)
		quit(cub, ER_MAPGEN);
	y = -1;
	while (cub->map[++y])
	{
		if (check_is_empty(cub->map[y]))
			quit(cub, "Invalid Map: There is an empty line");
		check_map(cub, y);
	}
	get_player_position(cub, cub->map);
}
