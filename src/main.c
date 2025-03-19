/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:44:50 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/19 14:38:04 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	ft_bzero(cub, sizeof(t_game));
	cub->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!cub->player)
		quit(cub, "Memory allocation fail - t_player");
	cub->bground = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!cub->bground)
		quit(cub, "Memory allocation fail - t_bground");
	cub->render = (t_render *)ft_calloc(1, sizeof(t_render));
	if (!cub->render)
		quit(cub, "Memory allocation fail - t_render");
	cub->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (!cub->ray)
		quit(cub, "Memory allocation fail - t_ray");
	ft_bzero(cub->wall, sizeof(t_texture) * 4);
	ft_bzero(&cub->key, sizeof(t_key));
	cub->ceiling = -1;
	cub->floor = -1;
}

int	gameloop(t_game *cub)
{
	draw_background(cub);
	handle_move(cub);
	render(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->bground->img, 0, 0);
	return (0);
}

void	load_game(t_game cub)
{
	init_game(&cub);
	mlx_hook(cub.win, 2, 1L << 0, keypress, &cub);
	mlx_hook(cub.win, 3, 1L << 1, keyrelease, &cub);
	mlx_hook(cub.win, 17, 0, exit_game, &cub);
	mlx_loop_hook(cub.mlx, gameloop, &cub);
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
