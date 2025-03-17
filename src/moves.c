/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:15:55 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/17 18:21:11 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_colliding(t_game *cub, double x, double y)
{
	double margin;
	
	margin = 0.25;
	if (cub->map[(int)(y + margin)][(int)(x + margin)] == '1' ||
		cub->map[(int)(y - margin)][(int)(x + margin)] == '1' ||
		cub->map[(int)(y + margin)][(int)(x - margin)] == '1' ||
		cub->map[(int)(y - margin)][(int)(x - margin)] == '1')
		return (true); // Há colisão
	return (false); // Sem colisão
}

void	move_forward_or_backward(t_game *cub, bool forward)
{
	double new_x;
	double new_y;

	if(forward)
	{
		new_x = cub->player->pos.x + cub->player->dir.x * MOVE_SPEED;
		new_y = cub->player->pos.y + cub->player->dir.y * MOVE_SPEED;
		if (!is_colliding(cub, new_x, cub->player->pos.y)
			&& !is_colliding(cub, cub->player->pos.x, new_y))
		{
			cub->player->pos.x = new_x;
			cub->player->pos.y = new_y;
		}
	}
	else
	{
		new_x = cub->player->pos.x - cub->player->dir.x * MOVE_SPEED;
		new_y = cub->player->pos.y - cub->player->dir.y * MOVE_SPEED;
		if (!is_colliding(cub, new_x, cub->player->pos.y)
			&& !is_colliding(cub, cub->player->pos.x, new_y))
		{
			cub->player->pos.x = new_x;
			cub->player->pos.y = new_y;
		}
	}
}

void	move_left_or_right(t_game *cub, bool left)
{
	double new_x;
	double new_y;

	if(left)
	{
		new_x = cub->player->pos.x + sin(cub->player->angle) * MOVE_SPEED;
		new_y = cub->player->pos.y - cos(cub->player->angle) * MOVE_SPEED;
		if (!is_colliding(cub, new_x, cub->player->pos.y)
			&& !is_colliding(cub, cub->player->pos.x, new_y))
		{
			cub->player->pos.x = new_x;
			cub->player->pos.y = new_y;
		}
	}
	else
	{
		new_x = cub->player->pos.x - sin(cub->player->angle) * MOVE_SPEED;
		new_y = cub->player->pos.y + cos(cub->player->angle) * MOVE_SPEED;
		if (!is_colliding(cub, new_x, cub->player->pos.y)
			&& !is_colliding(cub, cub->player->pos.x, new_y))
		{
			cub->player->pos.x = new_x;
			cub->player->pos.y = new_y;
		}
	}
}

void	handle_move(t_game *cub)
{
	if (cub->key.foward)
		move_forward_or_backward(cub, true);
	if (cub->key.backward)
		move_forward_or_backward(cub, false);
	if (cub->key.left)
		move_left_or_right(cub, true);
	if (cub->key.right)
		move_left_or_right(cub, false);
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

/*
void move_backward(t_game *cub)
{
	double new_x;
	double new_y;

	new_x = cub->player->pos.x - cub->player->dir.x * MOVE_SPEED;
	new_y = cub->player->pos.y - cub->player->dir.y * MOVE_SPEED;
	if (!is_colliding(cub, new_x, cub->player->pos.y)
		&& !is_colliding(cub, cub->player->pos.x, new_y))
	{
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	}
}

void move_left(t_game *cub)
{
	double new_x;
	double new_y;

	new_x = cub->player->pos.x + sin(cub->player->angle) * MOVE_SPEED;
	new_y = cub->player->pos.y - cos(cub->player->angle) * MOVE_SPEED;
	if (!is_colliding(cub, new_x, cub->player->pos.y)
		&& !is_colliding(cub, cub->player->pos.x, new_y))
	{
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	}
}

void move_right(t_game *cub)
{
	double new_x;
	double new_y;

	new_x = cub->player->pos.x - sin(cub->player->angle) * MOVE_SPEED;
	new_y = cub->player->pos.y + cos(cub->player->angle) * MOVE_SPEED;
	if (!is_colliding(cub, new_x, cub->player->pos.y)
		&& !is_colliding(cub, cub->player->pos.x, new_y))
	{
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	}
}
*/
