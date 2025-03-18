/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:55:37 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/18 15:57:56 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	parse_map(t_game *cub)
{
	int	y;
	
	if (!cub->map)
		quit(cub, ER_MAPGEN);
	y = -1;
	while(cub->map[++y])
	{
		check_is_empty(cub, cub->map[y]);
		check_valid_characters(cub, cub->map[y]);
		check_map(cub, y);
	}
	get_player_position(cub, cub->map);
}*/

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
				return;
			}
		}
	}
	if (cub->player->pov == 0)
		 	quit(cub, "Invalid map. Player is not set");
}

void	check_is_empty(t_game *cub, char *row) // ja e feita essa verificacao
{
	while (*row == ' ' || *row == '\n')
		row++;
	if (*row == '\0')
		quit(cub, "Map is not valid: There is a empty line");
}

void	check_map(t_game *cub, int y)
{
	int			x;
	static int	count_player;
	
	x = -1;
	while(cub->map[y][++x])
	{
		if (!ft_strchr("01NSEW \n", cub->map[y][x]))
			quit(cub, "Invalid map. There is an invalid character");
		if (ft_strchr("0NSEW", cub->map[y][x]))
		{
			if (ft_strchr("NSEW", cub->map[y][x]))
				count_player++;
			if(count_player > 1)
				quit(cub, "Invalid map. There is more than 1 player");
			if(x == 0 || y == 0 || !cub->map[y + 1]
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
	while(cub->map[++y])
	{
		check_is_empty(cub, cub->map[y]); //verificar com a sofia
		check_map(cub, y);
	}
	get_player_position(cub, cub->map);
}


// void	parse_map(t_game *cub, char **map)
// {
// 	int	y;
// 	int	x;
	
// 	y = -1;
// 	while(map[++y])
// 	{
// 		check_is_empty(cub, map[y]);
// 		check_valid_characters(cub, map[y]);
// 		check_map(cub, y);
// 	}
// 	get_player_position(cub, cub->map);
// }

/*void	check_is_player_set(t_game *cub, char *line)
{
	static int	count_player;
	
	while(*line)
	{
		if(count_player > 1)
			quit(cub, "Map is not valid: There is more than 1 player");
		if(*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
			count_player++;
	}
}*/