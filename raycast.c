/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:16:23 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/26 18:34:55 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_delta_distance_y(t_game *cub, double ray_dir_y) // Passo e direção inicial do raio
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

void	dda(t_game *cub) //Algoritmo Digital Differential Analyzer (DDA)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->ray->side.x < cub->ray->side.y)
		{
			cub->ray->side.x += cub->ray->delta.x;
			cub->ray->map_x += cub->ray->step_x;
			cub->ray->side_axis = 0; // Colisão eixo x (horizontal)
		}
		else
		{
			cub->ray->side.y += cub->ray->delta.y;
			cub->ray->map_y += cub->ray->step_y;
			cub->ray->side_axis = 1; // Colisão eixo y (vertical)
		}
		//if (cub->map->map[cub->ray->map_y][cub->ray->map_x] == '1') // Se atingiu uma parede ('1' no mapa), parar o loop
		//	hit = 1;
	}
}

void	ray_info(t_game *cub, double ray_angle)
{
	double  hit_dist;
	
	cub->ray->dir.x = cos(ray_angle);
	cub->ray->dir.y = sin(ray_angle);
	cub->ray->map_x = (int)cub->player->pos.x;
	cub->ray->map_y = (int)cub->player->pos.y;
	cub->ray->delta.x = fabs(1 / cub->ray->dir.x); //Comprimento do raio de uma borda da célula até a próxima - (INICIAL, depois e atualizado)
	cub->ray->delta.y = fabs(1 / cub->ray->dir.y);
	get_delta_distance_x(cub, cub->ray->dir.x);
	get_delta_distance_y(cub, cub->ray->dir.y);
	dda(cub);
	if (cub->ray->side_axis == 0)
		hit_dist = cub->ray->side.x - cub->ray->delta.x;
	else
		hit_dist = cub->ray->side.y - cub->ray->delta.y;
	cub->ray->hit.x = cub->player->pos.x + hit_dist * cub->ray->dir.x;
	cub->ray->hit.y = cub->player->pos.y + hit_dist * cub->ray->dir.y;
	
	if (cub->ray->side_axis == 0) // Colisão x
	{
		if (cub->ray->step_x > 0)
		cub->render->nbr_text = (int)EA; // Parede Leste 
		else
		cub->render->nbr_text = (int)WE; // Parede Oeste
	}
	else // Colisão y
	{
		if (cub->ray->step_y > 0)
			cub->render->nbr_text = (int)SO; // Parede Sul
		else
			cub->render->nbr_text = (int)NO; // Parede Norte
	}
}

