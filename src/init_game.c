/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:19:36 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/19 15:51:05 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		quit(cub, "Fail to initialize MLX");
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->win)
		quit(cub, "Fail to create Window");
	init_background(cub);
	init_textures(cub);
	init_player(cub);
}

void	init_background(t_game *cub)
{
	cub->bground->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->bground->img)
		quit(cub, "Fail to initialize background image");
	cub->bground->addr = mlx_get_data_addr(cub->bground->img, \
		&cub->bground->bpp, &cub->bground->size_line, &cub->bground->endian);
	if (!cub->bground->addr)
		quit(cub, "Fail to get background data adress");
}

void	init_textures(t_game *cub)
{
	int		i;
	int		t_size;
	char	**texture_path;

	i = -1;
	t_size = (int)SIZE;
	texture_path = (char **)malloc(sizeof(char *) * 4);
	if (!texture_path)
		quit(cub, "Memory allocation fail - texture_path");
	texture_path[0] = cub->no_texture;
	texture_path[1] = cub->so_texture;
	texture_path[2] = cub->ea_texture;
	texture_path[3] = cub->we_texture;
	while (++i < 4)
	{
		cub->wall[i].img = mlx_xpm_file_to_image(cub->mlx, texture_path[i], \
			&t_size, &t_size);
		if (!cub->wall[i].img)
			quit(cub, "Fail to load texture");
		cub->wall[i].addr = mlx_get_data_addr(cub->wall[i].img, \
			&cub->wall[i].bpp, &cub->wall[i].size_line, &cub->wall[i].endian);
		if (!cub->wall[i].addr)
			quit(cub, "Fail to get texture data adress");
	}
	free(texture_path);
}

void	init_player(t_game	*cub)
{
	cub->player->pos.x += 0.5;
	cub->player->pos.y += 0.5;
	if (cub->player->pov == 'N')
		cub->player->angle = 3 * PI / 2;
	else if (cub->player->pov == 'S')
		cub->player->angle = PI / 2;
	else if (cub->player->pov == 'E')
		cub->player->angle = 0;
	else if (cub->player->pov == 'W')
		cub->player->angle = PI;
	cub->player->dir.x = cos(cub->player->angle);
	cub->player->dir.y = sin(cub->player->angle);
	cub->fov = 60 * (PI / 180);
}
