/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:15:55 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/26 18:40:16 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos.x + cub->player->dir.x * MOVE_SPEED;
	new_y = cub->player->pos.y + cub->player->dir.y * MOVE_SPEED;
	if (cub->map.map[(int)cub->player->pos.y][(int)new_x] != '1') //
		cub->player->pos.x = new_x;
	if (cub->map.map[(int)new_y][(int)cub->player->pos.x] != '1')
		cub->player->pos.y = new_y;
}

void	move_backward(t_game *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos.x - cub->player->dir.x * MOVE_SPEED;
	new_y = cub->player->pos.y - cub->player->dir.y * MOVE_SPEED;
	if (cub->map.map[(int)cub->player->pos.y][(int)new_x] != '1')
		cub->player->pos.x = new_x;
	if (cub->map.map[(int)new_y][(int)cub->player->pos.x] != '1')
		cub->player->pos.y = new_y;
}

void	move_left(t_game *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos.x + sin(cub->player->angle)* MOVE_SPEED;
	new_y = cub->player->pos.y - cos(cub->player->angle) * MOVE_SPEED;
	if (cub->map.map[(int)cub->player->pos.y][(int)new_x] != '1') //se for necessario é possivel + e - um pequeno valor para ter um limite de segurança que impeça o jogador de ficar muito proximo as paredes (BOUNDARY) 
		cub->player->pos.x = new_x;
	if (cub->map.map[(int)new_y][(int)cub->player->pos.x] != '1')
		cub->player->pos.y = new_y;
}

void	move_right(t_game *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos.x - sin(cub->player->angle)* MOVE_SPEED;
	new_y = cub->player->pos.y + cos(cub->player->angle) * MOVE_SPEED;
	if (cub->map.map[(int)cub->player->pos.y][(int)new_x] != '1')
		cub->player->pos.x = new_x;
	if (cub->map.map[(int)new_y][(int)cub->player->pos.x] != '1')
		cub->player->pos.y = new_y;
}

void	handle_move(t_game *cub)
{
	if (cub->key.foward)
		move_forward(cub);
	if (cub->key.backward)
		move_backward(cub);
	if (cub->key.left)
		move_left(cub);
	if (cub->key.right)
		move_right(cub);
	if (cub->key.rot_left)
	{
		cub->player->angle -= ROTATE;
		cub->player->dir.x = cos(cub->player->angle);
		cub->player->dir.y = sin(cub->player->angle);
	}
	if (cub->key.rot_right)
	{
		cub->player->angle += ROTATE;
		cub->player->dir.x = cos(cub->player->angle);
		cub->player->dir.y = sin(cub->player->angle);
	}
}
