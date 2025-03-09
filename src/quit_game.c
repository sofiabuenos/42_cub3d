/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:16:39 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/09 14:05:22 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (cub->wall[i].img)
			mlx_destroy_image(cub->mlx, cub->wall[i].img);
	}
}

int	quit_game(t_game *cub)
{
	if (!cub)
		return (1);
	if (cub->wall)
		free_textures(cub);
	//if(cub->bground)
	//	mlx_destroy_image(cub->mlx, cub->bground->img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	//free(cub->player);
	//free(cub->render);
	//free(cub->ray);
	exit(EXIT_FAILURE);
}

void	error_msg(t_game *cub, char *msg)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	quit_game(cub);
	return;
}