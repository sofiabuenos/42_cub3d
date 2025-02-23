/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:16:39 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/20 17:50:21 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (cub->img[i].img)
			mlx_destroy_image(cub->mlx, cub->img[i].img);
	}
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
}

void	quit_game(t_game *cub)
{
	if (!cub)
	return ;
	if (cub->img)
	free_textures(cub->img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	
	
}

void	error_msg(char *msg, t_game *cub)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	quit_game(cub);
}