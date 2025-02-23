/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:19:36 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/23 18:13:20 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *cub)
{
	cub->mlx = mlx_init();
	if(!cub->mlx)
		error_msg(cub, "Fail to initialize MLX");
	init_textures(cub);
	//cub->screen_h = (int)HEIGHT;
	//cub->screen_w = (int)WIDTH;
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if(!cub->win)
		error_msg(cub, "Fail to initialize MLX");
}

void	init_textures(t_game *cub)
{
	int	i;
	int	t_size;

	i = -1;
	//t_size = (int)SIZE;

	//E preciso definfir cada textura com base no seu endereço definido no mapa;
	//cub->texture[0] = north;
	//cub->texture[1] = south;
	//cub->texture[2] = east;
	//cub->texture[3] = west;
	
	while(++i < 4)
	{
		cub->img[i].img = mlx_xpm_file_to_image(cub->mlx, cub->texture[i], SIZE, SIZE);
		if(!cub->img[i].img)
			error_msg(cub, "Fail to load texture");
		cub->img[i].addr = mlx_get_data_addr(cub->img[i].img, &cub->img[i].bpp, &cub->img[i].size_line, &cub->img[i].endian);
		if(!cub->img[i].addr)
			error_msg(cub, "Fail to get texture adress");
	}
}

void	init_player(t_game	*cub)
{
	//cub->player->pos.x = + 0.5;
	//cub->player->pos.y = + 0.5;

	if(cub->player->pov == 'N')
		cub->player->angle = PI + (PI / 2);
	else if(cub->player->pov == 'S')
		cub->player->angle = PI / 2;
	else if(cub->player->pov == 'E')
		cub->player->angle = 0;
	else if(cub->player->pov == 'W')
		cub->player->angle = PI;
	cub->player->dir.x = cos(cub->player->angle) * MOVE_SPEED;
	cub->player->dir.y = sen(cub->player->angle) * MOVE_SPEED;
}

void	init_backgroungd(t_game *cub)
{
	cub->bground->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->bground->img)
		error_msg(cub, "Fail to load background");
	cub->bground->addr = mlx_get_data_addr(cub->bground->img, &cub->bground->bpp, &cub->bground->size_line,
			&cub->bground->endian);
	if (!cub->bground->addr)
		error_msg(cub, "Fail to get background adress");
}

/*void	my_mlx_pixel_put(t_texture	*bground, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = bground->addr + (y * bground->size_line + x * (bground->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	background(t_game *cub)
{
	int	x;
	int	y;
	int	color;

	y = -1;

	//color = e preciso saber como vou receber a cor, se vai estar ja em RGB ou se tenho que fazer um split; (t << 24 | r << 16 | g << 8 | b)
	color = (ceiling_color);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y > HEIGHT / 2)
				color = (floor_color);
			my_mlx_pixel_put(cub->bground, x, y, color);
		}
	}
}*/




