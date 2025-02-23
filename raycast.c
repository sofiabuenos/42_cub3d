/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:16:23 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/23 22:00:32 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_delta_distance_y(t_game *cub3d, double ray_dir_y)
{
	if (ray_dir_y < 0)
	{
		cub3d->ray->step_y = -1;
		cub3d->ray->side_y = cub3d->ray->delta_y
		* (cub3d->player->pos->y - cub3d->ray->map_y);
	}
	else
	{
		cub3d->ray->step_y = 1;
		cub3d->ray->side_y = cub3d->ray->delta_y
		* (cub3d->ray->map_y + 1.0 - cub3d->player->pos->y);
	}
}

void	get_delta_distance_x(t_game *cub3d, double ray_dir_x)
{
	if (ray_dir_x < 0)
	{
		cub3d->ray->step_x = -1;
		cub3d->ray->side_x = cub3d->ray->delta_x
			* (cub3d->player->pos->x - cub3d->ray->map_x);
		}
		else
		{
			cub3d->ray->step_x = 1;
		cub3d->ray->side_x = cub3d->ray->delta_x
		* (cub3d->ray->map_x + 1.0 - cub3d->player->pos->x);
	}
}

void	get_delta_distance(t_game *cub3d, double ray_dir_x, double ray_dir_y)
{
	cub3d->ray->delta_x = fabs(1 / ray_dir_x);
	cub3d->ray->delta_y = fabs(1 / ray_dir_y);
	get_delta_distance_x(cub3d, ray_dir_x);
	get_delta_distance_y(cub3d, ray_dir_y);
}

void	dda(t_game *cub3d)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub3d->ray->side_x < cub3d->ray->side_y)
		{
			cub3d->ray->side_x += cub3d->ray->delta_x;
			cub3d->ray->map_x += cub3d->ray->step_x;
			cub3d->ray->side = 0;
		}
		else
		{
			cub3d->ray->side_y += cub3d->ray->delta_y;
			cub3d->ray->map_y += cub3d->ray->step_y;
			cub3d->ray->side = 1;
		}
		//if (cub3d->map->map[cub3d->ray->map_y][cub3d->ray->map_x] == '1')
		//	hit = 1;
	}
}

void	cast_ray(t_game *cub3d, double ray_angle)
{
	double	ray_dir_x;
	double	ray_dir_y;
	
	ray_dir_x = cos(ray_angle);
	ray_dir_y = sin(ray_angle);
	cub3d->ray->map_x = (int)cub3d->player->pos->x;
	cub3d->ray->map_y = (int)cub3d->player->pos->y;
	get_delta_distance(cub3d, ray_dir_x, ray_dir_y);
	dda(cub3d);
	
	
}