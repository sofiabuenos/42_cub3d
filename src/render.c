/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:15:26 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:54 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_game *cub)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	cub->ceiling = convert_to_argb(cub->c_color, cub);
	cub->floor = convert_to_argb(cub->f_color, cub);
	color = cub->ceiling;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y > HEIGHT / 2)
				color = cub->floor;
			my_mlx_pixel_put_color(cub->bground, x, y, color);
		}
	}
}

void	get_wall_collision(t_game *cub)
{
	if (cub->ray->side_axis == 1)
	{
		if (cub->ray->step_y > 0)
			cub->render->wall_x = 1.0 - (cub->ray->hit.x - \
			floor(cub->ray->hit.x));
		else
			cub->render->wall_x = cub->ray->hit.x - floor(cub->ray->hit.x);
	}
	else
	{
		if (cub->ray->step_x < 0)
			cub->render->wall_x = 1.0 - (cub->ray->hit.y - \
			floor(cub->ray->hit.y));
		else
			cub->render->wall_x = (cub->ray->hit.y) - floor(cub->ray->hit.y);
	}
}

void	draw_walls(t_game *cub, int x, int begin, int end)
{
	int	y;

	get_wall_collision(cub);
	cub->render->text_x = cub->render->wall_x * (int)SIZE;
	if (cub->render->text_x >= (int)SIZE)
		cub->render->text_x = (int)SIZE - 1;
	cub->render->wall_height = end - begin;
	cub->render->scale = (double)SIZE / cub->render->wall_height;
	y = begin - 1;
	while (++y < end)
	{
		cub->render->text_y = (int)((y - begin) * cub->render->scale) % SIZE;
		if (cub->render->text_y >= (int)SIZE)
			cub->render->text_y = (int)SIZE - 1;
		cub->render->color = my_mlx_pixel_get_color(&cub->ray->texture, \
		cub->render->text_x, cub->render->text_y);
		my_mlx_pixel_put_color(cub->bground, x, y, cub->render->color);
	}
}

void	render(t_game *cub)
{
	int		x;
	double	wall_dist;

	x = 0;
	cub->render->text_step = cub->fov / WIDTH;
	while (x < WIDTH)
	{
		cub->render->texture_pos = cub->player->angle - (cub->fov / 2) \
		+ (x * cub->render->text_step);
		ray_data(cub, cub->render->texture_pos);
		wall_dist = HEIGHT / (cub->ray->hit_dist \
		* cos(cub->render->texture_pos - cub->player->angle));
		if (wall_dist <= 0)
			wall_dist = HEIGHT;
		cub->render->draw_start = (HEIGHT / 2) - (int)wall_dist / 2;
		cub->render->draw_end = (HEIGHT / 2) + (int)wall_dist / 2;
		draw_walls(cub, x, cub->render->draw_start, cub->render->draw_end);
		x++;
	}
}
