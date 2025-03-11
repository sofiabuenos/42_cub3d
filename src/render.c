/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:15:26 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/11 15:58:32 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_game *cub)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	color = (cub->ceiling);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y > HEIGHT / 2)
				color = (cub->floor);
			my_mlx_pixel_put_color(cub->bground, x, y, color);
		}
	}
}

void	draw_walls(t_game *cub, int x, int begin, int end)
{
	int	y;
	
	if (cub->ray->side_axis == 1)
	{
		if (cub->ray->step_y > 0) // Parede Sul
			cub->render->wall_x = 1.0 - (cub->ray->hit.x - floor(cub->ray->hit.x));
		else // Parede Norte
			cub->render->wall_x = cub->ray->hit.x - floor(cub->ray->hit.x);
	}
	// if (cub->ray->side_axis == 1)
	// 	cub->render->wall_x = (cub->ray->hit.x + 0.0001) - floor(cub->ray->hit.x);
	else
		cub->render->wall_x = (cub->ray->hit.y) - floor(cub->ray->hit.y);
	cub->render->text_x = cub->render->wall_x * (int)SIZE;
	if(cub->render->text_x >= (int)SIZE)
		cub->render->text_x = (int)SIZE - 1;
	cub->render->wall_height = end - begin;
	cub->render->scale = (double)SIZE / cub->render->wall_height;
	y = begin;
	while(y < end)
	{
		cub->render->text_y = (int)((y - begin) * cub->render->scale) % ((int)SIZE);
		if(cub->render->text_y >= (int)SIZE)
			cub->render->text_y = (int)SIZE - 1;
		cub->render->color = my_mlx_pixel_get_color(&cub->ray->texture, cub->render->text_x, cub->render->text_y);
		my_mlx_pixel_put_color(cub->bground, x, y, cub->render->color);
		y++;
		//printf("\n hit_x: %f\n hit_y: %f\n", cub->ray->hit.x, cub->ray->hit.y);
		//printf(" Text_x: %d\n Wall_x: %f\n", cub->render->text_x, cub->render->wall_x);
		//printf(" Text_y: %d\n Color: %d\n", cub->render->text_y, cub->render->color);
	}
}

void	define_draw_points(t_game *cub)
{
	double	wall_dist;
	//double	wall_disty;
	
	wall_dist = HEIGHT / (cub->ray->hit_dist * cos(cub->render->texture_pos - cub->player->angle));
	if(wall_dist <= 0)
		wall_dist = HEIGHT;
	cub->render->draw_start = (HEIGHT / 2) - (int)wall_dist / 2;
	cub->render->draw_end = (HEIGHT / 2) + (int)wall_dist / 2;
}


void	render(t_game *cub)
{
	int	x;
	
	x = 0;
	cub->render->text_step = cub->fov / WIDTH;
	while(x < WIDTH)
	{
		cub->render->texture_pos = cub->player->angle - (cub->fov / 2) + (x * cub->render->text_step);
		ray_info(cub, cub->render->texture_pos);
		define_draw_points(cub);
		draw_walls(cub, x, cub->render->draw_start, cub->render->draw_end);
		x++;
	}
}