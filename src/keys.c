/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:35:13 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/03 16:44:33 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress(int keycode, t_game *cub)
{
	if (keycode == W)
		cub->key.foward = 1;
	else if (keycode == S)
		cub->key.backward = 1;
	else if (keycode == A)
		cub->key.left = 1;
	else if (keycode == D)
		cub->key.right = 1;
	else if (keycode == LEFT)
		cub->key.rot_left = 1;
	else if(keycode == RIGHT)
		cub->key.rot_right = 1;
	return (0);
}

int	keyrelease(int keycode, t_game *cub)
{
	if (keycode == ESC)
		quit_game(cub);	
	if (keycode == W)
		cub->key.foward = 0;
	else if (keycode == S)
		cub->key.backward = 0;
	else if (keycode == A)
		cub->key.left = 0;
	else if (keycode == D)
		cub->key.right = 0;
	else if (keycode == LEFT)
		cub->key.rot_left = 0;
	else if(keycode == RIGHT)
		cub->key.rot_right = 0;
	return (0);
}
