/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:16:23 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/19 15:25:08 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_delta_distance_y(t_game *cub, double ray_dir_y)
{
	if (ray_dir_y < 0)
	{
		cub->ray->step_y = -1;
		cub->ray->side.y = cub->ray->delta.y
			* (cub->player->pos.y - cub->ray->map_y);
	}
	else
	{
		cub->ray->step_y = 1;
		cub->ray->side.y = cub->ray->delta.y
			* (cub->ray->map_y + 1.0 - cub->player->pos.y);
	}
}

void	get_delta_distance_x(t_game *cub, double ray_dir_x)
{
	if (ray_dir_x < 0)
	{
		cub->ray->step_x = -1;
		cub->ray->side.x = cub->ray->delta.x
			* (cub->player->pos.x - cub->ray->map_x);
	}
	else
	{
		cub->ray->step_x = 1;
		cub->ray->side.x = cub->ray->delta.x
			* (cub->ray->map_x + 1.0 - cub->player->pos.x);
	}
}

void	dda(t_game *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->ray->side.x < cub->ray->side.y)
		{
			cub->ray->side.x += cub->ray->delta.x;
			cub->ray->map_x += cub->ray->step_x;
			cub->ray->side_axis = 0;
		}
		else
		{
			cub->ray->side.y += cub->ray->delta.y;
			cub->ray->map_y += cub->ray->step_y;
			cub->ray->side_axis = 1;
		}
		if (cub->map[cub->ray->map_y][cub->ray->map_x] == '1')
			hit = 1;
	}
}

void	get_texture_index(t_game *cub)
{
	if (cub->ray->side_axis == 0)
	{
		if (cub->ray->step_x > 0)
			cub->ray->texture = cub->wall[2];
		else
			cub->ray->texture = cub->wall[3];
	}
	else
	{
		if (cub->ray->step_y >= 0)
			cub->ray->texture = cub->wall[1];
		else
			cub->ray->texture = cub->wall[0];
	}
}

void	ray_data(t_game *cub, double ray_angle)
{
	cub->ray->dir.x = cos(ray_angle);
	cub->ray->dir.y = sin(ray_angle);
	cub->ray->map_x = (int)cub->player->pos.x;
	cub->ray->map_y = (int)cub->player->pos.y;
	cub->ray->delta.x = fabs(1 / cub->ray->dir.x);
	cub->ray->delta.y = fabs(1 / cub->ray->dir.y);
	get_delta_distance_x(cub, cub->ray->dir.x);
	get_delta_distance_y(cub, cub->ray->dir.y);
	dda(cub);
	if (cub->ray->side_axis == 0)
		cub->ray->hit_dist = cub->ray->side.x - cub->ray->delta.x;
	else
		cub->ray->hit_dist = cub->ray->side.y - cub->ray->delta.y;
	cub->ray->hit.x = cub->player->pos.x + cub->ray->hit_dist * cub->ray->dir.x;
	cub->ray->hit.y = cub->player->pos.y + cub->ray->hit_dist * cub->ray->dir.y;
	get_texture_index(cub);
}
