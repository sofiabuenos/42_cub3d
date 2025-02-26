/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:27:51 by sheila            #+#    #+#             */
/*   Updated: 2025/02/26 15:30:29 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void    ft_calculate_wall_projection(t_cub3d *cub3d, t_wall *wall, int i)
{
    double perpendicular_dist;
    int screen_height = cub3d->config->resolution.height;

    perpendicular_dist = wall->wall_dist * cos(wall->ray_angle - cub3d->player->angle);
    wall->height = (int)(screen_height / perpendicular_dist);
    wall->start = -wall->height / 2 + screen_height / 2;
    if (wall->start < 0)
        wall->start = 0;
    wall->end = wall->height / 2 + screen_height / 2;
    if (wall->end >= screen_height)
        wall->end = screen_height - 1;

    ft_render_wall(cub3d, wall, i);
}

void    ft_cast_single_ray(t_cub3d *cub3d, double ray_angle, int i)
{
    t_wall wall;
    double delta_dist_x, delta_dist_y;
    double side_dist_x, side_dist_y;
    int step_x, step_y;
    int hit = 0, side;

    wall.ray_angle = ray_angle;
    wall.dir_x = cos(ray_angle);
    wall.dir_y = sin(ray_angle);
    wall.map_x = (int)cub3d->player->pos_x;
    wall.map_y = (int)cub3d->player->pos_y;
    delta_dist_x = fabs(1 / wall.dir_x);
    delta_dist_y = fabs(1 / wall.dir_y);

    if (wall.dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (cub3d->player->pos_x - wall.map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (wall.map_x + 1.0 - cub3d->player->pos_x) * delta_dist_x;
    }

    if (wall.dir_y < 0)
    {
        step_y = -1;
        side_dist_y = (cub3d->player->pos_y - wall.map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (wall.map_y + 1.0 - cub3d->player->pos_y) * delta_dist_y;
    }

    while (!hit)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            wall.map_x += step_x;
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            wall.map_y += step_y;
            side = 1;
        }
        if (cub3d->map[wall.map_y][wall.map_x] == '1')
            hit = 1;
    }
   if (side == 0)
        wall.wall_dist = (wall.map_x - cub3d->player->pos_x + (1 - step_x) / 2) / wall.dir_x;
    else
        wall.wall_dist = (wall.map_y - cub3d->player->pos_y + (1 - step_y) / 2) / wall.dir_y;
}

void    ft_raycasting(t_cub3d *cub3d)
{
    double ray_angle;
    int screen_width = cub3d->config->resolution.width;
    double fov = cub3d->player->fov;
    double angle_step = fov / screen_width;

    for (int i = 0; i < screen_width; i++)
    {
        ray_angle = cub3d->player->angle - (fov / 2) + i * angle_step;
        ft_cast_single_ray(cub3d, ray_angle, i);
    }
}

*/