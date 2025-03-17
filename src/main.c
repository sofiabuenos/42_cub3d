/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:44:50 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/17 19:20:09 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gameloop(t_game *cub)
{
	draw_background(cub);
	handle_move(cub);
	render(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->bground->img, 0, 0);
	return(0);
}

void	load_game(t_game cub)
{
	init_game(&cub);
	mlx_hook(cub.win, 2, 1L << 0, keypress, &cub);
	mlx_hook(cub.win, 3, 1L << 1, keyrelease, &cub);
	mlx_hook(cub.win, 17, 0, exit_game, &cub);
	mlx_loop_hook(cub.mlx, gameloop , &cub);
	mlx_loop(cub.mlx);
}

int	main(int ac, char **av)
{
	t_game	cub;
	
	init(&cub);
	parse(&cub, ac, av);
	load_game(cub);
	return (0);
}
