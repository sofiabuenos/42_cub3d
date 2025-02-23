/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:20:15 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/20 17:00:09 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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