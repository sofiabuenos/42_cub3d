/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:15:26 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/23 17:34:56 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_texture	*bground, int x, int y, int color)
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
}