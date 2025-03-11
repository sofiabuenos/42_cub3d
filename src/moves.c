/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:15:55 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/11 15:56:32 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_colliding(t_game *cub, double x, double y)
{
	double margem = 0.25;

	// Checa colisão para os quatro cantos do jogador
	if (cub->map[(int)(y + margem)][(int)(x + margem)] == '1' ||
		cub->map[(int)(y - margem)][(int)(x + margem)] == '1' ||
		cub->map[(int)(y + margem)][(int)(x - margem)] == '1' ||
		cub->map[(int)(y - margem)][(int)(x - margem)] == '1')
		return true; // Há colisão

	return false; // Sem colisão
}

void move_forward(t_game *cub)
{
	double new_x = cub->player->pos.x + cub->player->dir.x * MOVE_SPEED;
	double new_y = cub->player->pos.y + cub->player->dir.y * MOVE_SPEED;

	printf("\nTentando mover para X: %f, Y: %f\n", new_x, new_y);

	if (!is_colliding(cub, new_x, cub->player->pos.y) && !is_colliding(cub, cub->player->pos.x, new_y))
	{
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	}
	// Verifica colisão antes de atualizar a posição
	// if (!is_colliding(cub, new_x, cub->player->pos.y))
	// 	cub->player->pos.x = new_x;
	// if (!is_colliding(cub, cub->player->pos.x, new_y))
	// 	cub->player->pos.y = new_y;
}

void move_backward(t_game *cub)
{
	double new_x = cub->player->pos.x - cub->player->dir.x * MOVE_SPEED;
	double new_y = cub->player->pos.y - cub->player->dir.y * MOVE_SPEED;

	printf("\nTentando mover para X: %f, Y: %f\n", new_x, new_y);

	if (!is_colliding(cub, new_x, cub->player->pos.y) && !is_colliding(cub, cub->player->pos.x, new_y))
	{
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	}
	// Verifica colisão antes de atualizar a posição
	// if (!is_colliding(cub, new_x, cub->player->pos.y))
	// 	cub->player->pos.x = new_x;
	// if (!is_colliding(cub, cub->player->pos.x, new_y))
	// 	cub->player->pos.y = new_y;
}
void move_left(t_game *cub)
{
	double new_x = cub->player->pos.x + sin(cub->player->angle) * MOVE_SPEED;
	double new_y = cub->player->pos.y - cos(cub->player->angle) * MOVE_SPEED;

	printf("\nTentando mover para X: %f, Y: %f\n", new_x, new_y);

	if (!is_colliding(cub, new_x, cub->player->pos.y) && !is_colliding(cub, cub->player->pos.x, new_y))
	{
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	}
	// if (!is_colliding(cub, new_x, cub->player->pos.y))
	// 	cub->player->pos.x = new_x;
	// if (!is_colliding(cub, cub->player->pos.x, new_y))
	// 	cub->player->pos.y = new_y;
}

void move_right(t_game *cub)
{
	double new_x = cub->player->pos.x - sin(cub->player->angle) * MOVE_SPEED;
	double new_y = cub->player->pos.y + cos(cub->player->angle) * MOVE_SPEED;

	printf("\nTentando mover para X: %f, Y: %f\n", new_x, new_y);

	if (!is_colliding(cub, new_x, cub->player->pos.y) && !is_colliding(cub, cub->player->pos.x, new_y))
	{
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	}
	// if (!is_colliding(cub, new_x, cub->player->pos.y))
	// 	cub->player->pos.x = new_x;
	// if (!is_colliding(cub, cub->player->pos.x, new_y))
	// 	cub->player->pos.y = new_y;
}

void	handle_move(t_game *cub)
{
	debug_player_position(cub);
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
