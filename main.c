/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:20:15 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/26 18:40:08 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_loophook(t_game *cub)
{
	//movimentacao
	//renderizacao do ceiling e floor (background)
	//renderizaçao das texturas (wall)
	//colocar a imagem na tela - mlx_put_image_to_window(cub->mlx, cub->win, cub->bground->img, 0, 0);
	
}


int	main(void)
{
	t_game	cub;
	
	ft_bzero(&cub, sizeof(t_game));
	init_mlx(&cub);
	
	mlx_hook(cub.win, 2, 1L << 0, keypress, &cub);
	mlx_hook(cub.win, 2, 1L << 0, keyrelease, &cub);
	mlx_hook(cub.win, 17, 0, quit_game, &cub);
	//mlx_loop_hook(cub.mlx, , &cub);
	mlx_loop(cub.mlx);
	return (0);
}